#include <iostream>
#include <vector>

using namespace ::std;
class Solution2 {
public:

    void moveZeroes(vector<int>& nums) {

        int k = 0;

        for(int i = 0; i < nums.size() ; i ++) {
            if(nums[i] != 0){
                nums[k] = nums[i];
                k++;
            }
        }

        for( k ;k < nums.size(); k ++){
            nums[k] = 0 ;
        }





        
    }
};