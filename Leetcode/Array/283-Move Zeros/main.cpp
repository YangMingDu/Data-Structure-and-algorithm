#include <iostream>
#include <vector>

using namespace ::std;
class Solution1 {
public:
//时间复杂度 O（n）
//空间复杂度 O（n）
    void moveZeroes(vector<int>& nums) {

        //创建一个数组，将所有非0的nums的元素放入
        vector<int> nonZeroElement ;
        for(int i = 0; i < nums.size() ; i ++){

            if(nums[i] != 0){
                nonZeroElement.push_back(nums[i]);
            }
        }

        //将nonZeroElement数组覆盖到nums数组
        for(int i = 0; i < nonZeroElement.size(); i++){
            nums[i] = nonZeroElement[i];
        }

        //将其他元素赋值为0
        for(int i = nonZeroElement.size(); i < nums.size(); i++){
            nums[i] = 0;
        }



        
    }
};