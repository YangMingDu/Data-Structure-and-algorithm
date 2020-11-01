
#include<iostream>
#include<vector>

using namespace :: std;
class Solution {
public:
    //记忆化搜索
    int breakInt(int n, vector<int> &memo){


        if(n == 0){
            return 0;
        }

        if(memo[n] != -1){
            return memo[n];
        }
        //res是int型最大值
        int res = INT_MAX;
        //至少分一次
        for(int i = 1; n- i*i >= 0; i++){
                //还能分的话，分的次数就加一再加上分完之后的值还需要分的次数的最小值。
                res = min(res,1+breakInt(n - i*i,memo));
                //记录每个数值向下分的最小值。避免之后的重复运算。
                memo[n] = res;
                

            }
        
        
        return res;

    }






    int numSquares(int n) {

        vector<int> memo(n + 1,-1);
        return breakInt(n,memo);





    }
};