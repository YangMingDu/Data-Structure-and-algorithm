#include <vector>
using namespace ::std;
class Solution {
public:
    //滑动窗口
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1){
            return nums;
        }

        vector<int> res;
        int l = 0;
        int r = k-1;

        while(r < nums.size()){
            int maxNum = INT_MIN;
            for(int i = l; i <= r; i++){
                maxNum = max(maxNum, nums[i]); 
            }
            res.push_back(maxNum);

            l++;
            r++;
        }


        return res;
    }
};