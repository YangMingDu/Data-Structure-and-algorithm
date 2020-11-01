#include <vector>
#include <iostream>
#include <string>
using namespace ::std;

class Solution {
private:
    int n;
    vector<int> dp;

public:
    //动态规划
    int numDecodings(string s) {

        int n = s.size();
        if(n == 1 || s[0] == '0') return s[0] != '0';

        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for(int i = n - 1; i >= 0; i --)
            if(s[i] != '0'){
                //结果就是解当前的码的解法再加上解2个码的结果，接一个码的的结尾是i+1，解2个码的结尾是i+2，那么只要知道i+1和i+2之前有多少种解法就可以了。
                dp[i] = dp[i + 1];
                if(i + 1 < n && s.substr(i, 2) <= "26") dp[i] += dp[i + 2];
            }

        return dp[0];
    }
};

