#include<vector>
#include<algorithm>
using namespace ::std;
class Solution {
public:
    //求中位数
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        sort(nums.begin(),nums.end());
        return nums[n/2];
    }
};