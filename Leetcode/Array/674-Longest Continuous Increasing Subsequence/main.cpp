#include <vector>
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {

        if(nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            return 1;
        }

        int leftPointer = -1;
        int rightPointer = 0;
        int res = 0;
        while(rightPointer <= nums.size()){
            leftPointer = rightPointer;  
            while (++rightPointer < nums.size() && nums[rightPointer] > nums[rightPointer - 1]);
            res = max(res, rightPointer - leftPointer);
        }

        return res;
    }
};