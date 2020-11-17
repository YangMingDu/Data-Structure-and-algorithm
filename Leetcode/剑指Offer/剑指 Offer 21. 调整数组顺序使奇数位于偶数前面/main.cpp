#include <iostream>
#include <vector>

using namespace ::std;
class Solution {
public:
    //双指针
    vector<int> exchange(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums;
        }
        
        int l = 0;
        int r = nums.size() - 1;
        while(l < r){
            if(nums[l] %2 != 0 && nums[r] % 2 == 0){
                l++;
                r--;
            }

            else if(nums[l] %2 != 0 && nums[r] % 2 != 0){
                l++;
            }
            else if(nums[l] %2 == 0 && nums[r] % 2 == 0){
                r--;
            }
            else{
                swap(nums[l],nums[r]);
                l++;
                r--;                
            }
        }

        return nums;
    }
};