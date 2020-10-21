#include <iostream>
#include <vector>

using namespace ::std;

class Solution1 {
public:
    //利用计数排序
    void sortColors(vector<int>& nums) {

        int count[3] = {0};

        for(int i = 0; i < nums.size(); i ++ ){
            count[nums[i]] ++;
        }


        int index = 0;

        for(int i = 0; i < count[0]; i ++ ){
            nums[index++] = 0;
        }
        for(int i = 0; i < count[1]; i ++ ){
            nums[index++] = 1;
        }
        for(int i = 0; i < count[2]; i ++ ){
            nums[index++] = 2;
        }
       /*  for(int i = 0; i < count[0]; i ++ ){
            nums[i] = 0;
        }

        for(int i = count[0]; i < (count[0] + count[1]); i++){
            nums[i] = 1;
        }

        for(int i = count[0] + count[1]; i < (count[0] + count[1]+ count[2]); i++){
            nums[i] = 2;
        } */

        
    }
};