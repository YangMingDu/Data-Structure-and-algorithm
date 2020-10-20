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
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] != nums[k]){
                nums[k+1]=nums[i];
                k++;
            }
            else{
                size --;
            }
        }
        return k+1;

    }
};