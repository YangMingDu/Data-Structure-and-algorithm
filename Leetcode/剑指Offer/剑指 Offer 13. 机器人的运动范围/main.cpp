#include <iostream>
#include <vector>
using namespace ::std;
class Solution {
public:
    vector<vector<bool>> isVisited;
    int count;
    //是否在边界内
    bool inArea(int x, int y,int m, int n,int k){
        return x >= 0 && y >= 0 && x < m && y < n;
    }
    //是否满足相加小于k的条件
    bool sumInArea(int x,int y,int k){
        int res = 0;
        while(x){
            res += x%10;
            x /= 10;
        }
        while(y){
            res += y%10;
            y /= 10;
        }

        return res <= k;
    }

    void pathDfs(int x,int y,int k,int m, int n){
        //满足所有条件且未被走过
        if(inArea(x,y,m,n,k) && sumInArea(x,y,k) && isVisited[x][y] == false){
            count ++;
            isVisited[x][y] = true;
        }
        else{
            return;
        }
        
        pathDfs(x-1,y,k,m,n);
        pathDfs(x,y-1,k,m,n);
        pathDfs(x+1,y,k,m,n);
        pathDfs(x,y+1,k,m,n);
    }


    int movingCount(int m, int n, int k) {
        isVisited = vector<vector<bool>>(m,vector<bool>(n,false));
        count = 0;
        pathDfs(0,0,k,m,n);
        return count;

    }
};