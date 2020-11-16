#include <vector>
using namespace ::std;
class Solution {
public:
    //  二分法
    int missingNumber(vector<int>& nums) {
        int low=0,high=nums.size()-1,n=nums.size();
        while(low<=high){
            int mid=(low+high)/2;
            //证明前面少数，应从前面寻找
            if(nums[mid]>mid){
                high=mid-1;
            }
            //后面少数
            else{
                low=mid+1;
            }
        }
        return low;
    }
};