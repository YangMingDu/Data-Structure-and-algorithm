#define  WIN32_LEAN_AND_MEAN//解决重定义
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <WinSock2.h>
#include <vector>

enum CMD {
    CMD_Login,
    CMD_Login_Result,
    CMD_Logout,
    CMD_Logout_Result,
    CMD_Error
};

//包头
struct DataHeader
{
    short dataLength;//数据长度
    short cmd;//命令
};
//Datapackage 包体
struct Login : public DataHeader
{
    Login() {
        dataLength = sizeof(Login);
        cmd = CMD_Login;
    }
    char userName[32];
    char passWord[32];
};
struct LoginResult : public DataHeader
{
    
    LoginResult() {
        dataLength = sizeof(LoginResult);
        cmd = CMD_Login_Result;
        result = 0;
    }
    int result;
    

};

struct Logout : public DataHeader
{
    Logout() {
        dataLength = sizeof(Logout);
        cmd = CMD_Logout;
    }
    char userName[32];

};

struct LogoutResult : public DataHeader
{
    LogoutResult() {
        dataLength = sizeof(LogoutResult);
        cmd = CMD_Logout_Result;
        result = 0;
    }
    int result;
};

std::vector<SOCKET> g_clients;


int processor(SOCKET _cSock) {
    //缓冲区
    char szRecv[4096] = {};
    //5.接收客户端的数据
    
    int nLen = recv(_cSock,szRecv, sizeof(DataHeader), 0);
    DataHeader* header = (DataHeader*)szRecv;
    if (nLen <= 0) {
        printf("Client quit\n");
        return -1;
    }
    //6.处理请求
    switch (header->cmd) {
    case CMD_Login:
    {
        recv(_cSock, szRecv + sizeof(DataHeader), header->dataLength - sizeof(DataHeader), 0);
        Login* login = (Login*)szRecv;
        printf("Recieve CMD: CMD_LOGIN  , Length of data: %d , userName is %s  ,Password = %s \n", login->dataLength, login->userName, login->passWord);
        //忽略判断验证用户名密码 

        LoginResult ret;
        send(_cSock, (char*)&ret, sizeof(ret), 0);

    }
    break;
    case CMD_Logout:
    {
        Logout Logout = {};
        recv(_cSock, (char*)&Logout + sizeof(DataHeader), sizeof(Logout) - sizeof(DataHeader), 0);
        printf("Recieve CMD: CMD_LOGIN  , Length of data: %d , userName is %s \n", Logout.dataLength, Logout.userName);
        //忽略判断验证用户名密码

        LogoutResult ret;
        send(_cSock, (char*)&ret, sizeof(ret), 0);
    }
    break;
    default:
        header->cmd = CMD_Error;
        header->dataLength = 0;
        send(_cSock, (char*)&header, sizeof(header), 0);
        break;

    }
}


int main()
{
    WORD ver = MAKEWORD(2, 2);
    WSADATA dat;
    WSAStartup(ver, &dat);
    //------------------------

    //1.建立socket 套接字
    SOCKET _sock =  socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    //2.bind 绑定用于接收客户端连接的网络端口
    //初始化服务端地址信息的数据结构
    sockaddr_in _sin = { };
    _sin.sin_family = AF_INET;
    _sin.sin_port = htons(4567);
    //_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");指定IP
    _sin.sin_addr.S_un.S_addr = INADDR_ANY;


    if (SOCKET_ERROR == bind(_sock, (sockaddr*)&_sin, sizeof(_sin))) {
        printf("ERROR,Cant bind\n");
    }
    else {
        printf("success bind\n");
    }
    //3.listen 监听网络端口

    if (SOCKET_ERROR == listen(_sock, 5)) {
        printf("ERROR,Cant listen\n");
    }
    else {
        printf("listenning\n");
    };//等待5个client进行链接


 

    while (1) {
        //伯克利 socket 描述符
        fd_set fdRead;
        fd_set fdWrite;
        fd_set fdExp;
        FD_ZERO(&fdRead);
        FD_ZERO(&fdWrite);
        FD_ZERO(&fdExp);

        FD_SET(_sock, &fdRead);
        FD_SET(_sock, &fdWrite);
        FD_SET(_sock, &fdExp);

        for (int n = (int)g_clients.size()-1; n >= 0; n--) {
            FD_SET(g_clients[n], &fdRead);
        }

        /// nfds 是一个整数值 是指fd_set集合中所有描述符(socket)的范围，而不是数量
        /// 即是所有文件描述符的最大值+1 在Windows中这个参数可以写0
        int ret = select(_sock + 1, &fdRead, &fdWrite, &fdExp, NULL);
        if (ret < 0) {
            printf("select over\n");
            break;
        }

        if (FD_ISSET(_sock, &fdRead)) {
            FD_CLR(_sock,&fdRead);
            //4.accept 等待接收客户端连接
            sockaddr_in clientAddr = {};
            int nAddrLen = sizeof(clientAddr);
            SOCKET _cSock = INVALID_SOCKET;


            _cSock = accept(_sock, (sockaddr*)&clientAddr, &nAddrLen);
            if (INVALID_SOCKET == _cSock) {
                printf("invalid socket");
            }
            printf("Client add: socket =  %d,IP = %s \n", (int)_cSock, inet_ntoa(clientAddr.sin_addr));
            g_clients.push_back(_cSock);
        }

        for (size_t n = 0; n < fdRead.fd_count; n++) {
            if (processor(fdRead.fd_array[n]) == -1) {
                auto iter = find(g_clients.begin(), g_clients.end(), fdRead.fd_array[n]);
                if (iter != g_clients.end()) {
                    g_clients.erase(iter);
                }
            }
        }
    }
    for (size_t n = g_clients.size() - 1; n >= 0; n--) {
        closesocket(g_clients[n]);
    }
    

    //8.关闭socket

    closesocket(_sock);
    WSACleanup();
    printf("exit\n");
    getchar();

    return 0;
}

