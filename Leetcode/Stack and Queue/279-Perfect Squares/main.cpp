#include<queue>
#include<string>
#include<iostream>
#include<vector>

using namespace :: std;
class Solution {
public:
    //利用无权图最小路径解决问题
    int numSquares(int n) {
        //第一个int代表当前的数值，第二个int代表当前的步数
        queue<pair<int,int>> q;

        q.push(make_pair(n,0));
        //优化：设置每个节点的访问状态
        vector<bool> visited(n+1,false);
        
        while(!q.empty()){
            
            int nums = q.front().first;
            int step = q.front().second;

            q.pop();



   
                for(int i = 1; ; i ++){
                    int a = nums-i*i;
                        if(a < 0){
                            break;
                        }
                        //如果下一个是0，说明下一步就到了
                        if (a == 0){
                            return step+1;
                        }
                        //如果访问过了，那么肯定不是最小路径
                        if(a > 0 && visited[a] == false){
                            q.push(make_pair(a,step+1));
                            visited[a] = true;
                        }


                }
            




        }



        return false;







    }
};