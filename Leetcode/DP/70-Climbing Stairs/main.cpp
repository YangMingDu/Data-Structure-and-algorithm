#include <vector>
#include <iostream>

using namespace :: std;
class Solution {
public:
 //类似斐波那契数列，DP解法
    int climbStairs(int n) {

        vector<int> memo(n+1,-1);
        memo[0] = 1;
        memo[1] = 1;
        for(int i = 2; i <= n; i++){
            memo[i] = memo[i-1] + memo[i-2];
        }

        return memo[n];  


    }
};