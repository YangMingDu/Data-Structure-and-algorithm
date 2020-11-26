#include<vector>
using namespace ::std;
class Solution {
public:
    int binarySearch(int left, int right,int target,vector<int>& nums){
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] < target){
                left = mid + 1;
            }
            else if(nums[mid] == target ){
                return mid;
            }
            else{
                right = mid - 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return 0;
        }
        int count = 0;
        int left = 0;
        int right = nums.size() - 1 ;
        int position = binarySearch(left,right,target,nums);

        if(position == -1){
            return 0;
        }
        //向前向后分别遍历
        for(int i = position; i >= 0 ; i--){
            if(nums[i] == nums[position]){
                count ++ ;
            }
            else{
                break;
            }
        }
        for(int i = position; i < nums.size() ; i++){
            if(nums[i] == nums[position]){
                count ++ ;
            }
            else{
                break;
            }
        }

        return count -1;


    }
};