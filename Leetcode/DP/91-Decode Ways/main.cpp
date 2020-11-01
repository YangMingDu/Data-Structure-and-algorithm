#include <vector>
#include <iostream>
#include <string>
using namespace ::std;

class Solution {
private:
    int n;
    vector<int> dp;

public:
    //记忆化搜索
    int numDecodings(string s) {

        n = s.size();
        dp.resize(n, -1);
        //传入字符串和起点
        return dfs(s, 0);
    }

private:
    //每次传入字符串和起点
    int dfs(const string& s, int start){
        //如果起点已经过了最后一个字符
        if(start >= s.size()) return 1;
        //如果起点字符为0，无法解码，所以此时不加解码方式
        if(s[start] == '0') return 0;

        if(dp[start] != -1) return dp[start];
        
        //当只选择下面一个字符解码时
        int res = dfs(s, start + 1);
        //选择下面两个字符解码时，条件是他可解码，那么最后的结果就是选择一个字符解码和选择两个字符解码的和
        if(start + 1 < n && s.substr(start, 2) <= "26")
            res += dfs(s, start + 2);

        return dp[start] = res;
    }
};
/* public:
    int numDecodings(string s) {

        int n = s.size();
        vector<int>dp(n, -1);
        return dfs(s, 0,dp,n);
    }

private:
    int dfs(const string& s, int start,vector<int> &dp,int n){

        if(start >= s.size()) return 1;
        if(s[start] == '0') return 0;
        if(dp[start] != -1) return dp[start];

        int res = dfs(s, start + 1,dp,n);
        if(start + 1 < n && s.substr(start, 2) <= "26")
            res += dfs(s, start + 2,dp,n);
        return dp[start] = res;
    }
}; */