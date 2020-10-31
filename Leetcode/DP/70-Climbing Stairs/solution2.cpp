#include <vector>
#include <iostream>

using namespace :: std;
class Solution {
public:
//类似斐波那契数列，记忆化搜索解法
    vector<int> memo;

    int calcul(int n){

       if(n == 0 || n == 1){
            return 1;
        }
        if(memo[n] == -1){
            memo[n] = calcul(n-1)+ calcul(n-2);
        }
        return memo[n];        
    }

    int climbStairs(int n) {

        memo = vector<int>(n+1,-1);
        return calcul(n);
 

    }
};
