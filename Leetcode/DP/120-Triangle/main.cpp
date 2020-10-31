#include <vector>
#include <iostream>

using namespace :: std;
class Solution {
private:
    vector<int> dp;
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        dp = triangle[n - 1];
        for(int i = n - 2;i >= 0;--i) {
            for(int j = 0;j <= i;++j) {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};