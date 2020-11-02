#include <vector>
#include <iostream>

using namespace :: std;
class Solution {
public:


    int calculPath(int m, int n,vector<vector<int>> &vec){

        int res;
        //起点
        if(m == 0 && n == 0){
            return 1;
        }

        if(vec[m][n] != 0){
            return vec[m][n];
        }

        //没有碰边
        if(0 < m  && 0 < n){
            res = calculPath(m-1,n,vec) + calculPath(m,n-1,vec); 
        }
        //在边上，只能从上面下来
        if(m == 0 && n != 0){
            res = calculPath(m,n-1,vec);
        }
        //同理
        if(m != 0 && n == 0){
            res = calculPath(m-1,n,vec);
        }

        return vec[m][n] = res;





    }



    int uniquePaths(int m, int n) {

        vector<vector<int>> memo(m,vector<int>(n,0));


        return calculPath(m-1,n-1,memo);

    


    }
};