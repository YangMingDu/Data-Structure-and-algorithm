#include <vector>
using namespace ::std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //双指针
        int left = 0;
        int right = nums.size() - 1;
        vector<int> res;

        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum == target){
                res.push_back(nums[left]);
                res.push_back(nums[right]);
                break;
            }

            else if (sum > target){
                right--;
            }
            else{
                left ++;
            }
        }
        return res;
    }
};