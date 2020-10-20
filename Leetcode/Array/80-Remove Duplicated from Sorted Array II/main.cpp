#include <iostream>
#include <vector>

using namespace :: std;





class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int k = 0;
        if(size == 0){
            return 0;
        }
        if(size <= 2 && size > 0){
            return size;
        }
        for(int i = 2 ; i < nums.size(); i++){
            if(nums[i] != nums[k]){
                nums[k+2]=nums[i];
                k++;
            }
            else{
                size --;
            }
        }
        return k+2;      
    }
};