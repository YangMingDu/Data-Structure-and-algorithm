#include <iostream>
#include <vector>

using namespace :: std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = nums.size() + 1;
        int l = 0;
        int r = -1;
        int sum = 0;
        while(l < nums.size()){
            if( r+1 < nums.size() && sum < s){
                r++;
                sum += nums[r];

            }
            else{
                sum -= nums[l];
                l++;
            }
            if(sum >= s){
                res = min( res, r-l+1);
            }


        }

        if(res == nums.size() + 1){
            return 0;
        }
        return res;


    }
};