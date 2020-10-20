#include <iostream>
#include <vector>

using namespace ::std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int tmp;
        int k = 0;
        for(int i = 0; i < nums.size();i++){
            if(nums[i] != val){
                tmp = nums[i];
                nums[i] = nums[k];
                nums[k] = tmp;
                k++;
            }
            else{
                size --;
            }
        }
        return size;

    }
};