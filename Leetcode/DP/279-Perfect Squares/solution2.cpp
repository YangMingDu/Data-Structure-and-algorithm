
#include<iostream>
#include<vector>

using namespace :: std;
class Solution {

public:

    //动态规划，自底向上
    int numSquares(int n) {


        vector<int> memo(n + 1,INT_MAX);
        memo[0] = 0;
        memo[1] = 1;

        for(int i = 2; i <= n ; i++){
            //求每个memo[i]
            for(int j = 1; i - j * j >= 0; j ++){

                memo[i] = min(memo[i],1 + memo[i - j * j]);
            }
        }

        return memo[n];






    }
};