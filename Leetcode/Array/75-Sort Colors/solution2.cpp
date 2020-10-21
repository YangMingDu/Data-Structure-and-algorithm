#include <iostream>
#include <vector>

using namespace ::std;

class Solution1 {
public:
    //利用三路快排的思路进行排序
    void sortColors(vector<int>& nums) {

        int two = nums.size();
        int zero = -1;
        int i = 0;

        while(i < two){
            if(nums[i] > 1){
                swap(nums[i],nums[two-1]);
                two --;
            }
            else if(nums[i] < 1){
                swap(nums[i],nums[zero + 1]);
                zero ++;
                i++;
            }
            else{
                i++;
            }
        }
        

        
    }
};