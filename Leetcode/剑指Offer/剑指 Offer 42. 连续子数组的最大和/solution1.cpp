#include<vector>
using namespace ::std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0;
        int res = INT_MIN;
        for (int i = 0 ; i < nums.size(); i++) {
            //如果之前的和加上当前的值小于当前的值
            //说明最大的情况一定是从当前值开始重新来
            pre = max(pre + nums[i], nums[i]);
            //这里维护最大子串的和
            res = max(pre,res);
        }
        return res;
    }
};