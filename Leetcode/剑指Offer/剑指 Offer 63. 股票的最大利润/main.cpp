#include<vector>
#include<algorithm>
using namespace ::std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int minPrice = prices[0];
        int maxGap = 0;
        for(int i = 0; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]); // 更新最小值
            maxGap = max(maxGap, prices[i] - minPrice); // 更新最大差距值
        }
        return maxGap;
    }
};
