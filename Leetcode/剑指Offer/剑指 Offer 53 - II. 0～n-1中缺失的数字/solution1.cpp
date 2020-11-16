#include <vector>
using namespace ::std;
class Solution {
public:
    //遍历法
    int missingNumber(vector<int>& nums) {
        //看头
        if(nums[0] != 0){
            return 0;
        }
        //看中间
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - nums[i-1] == 2){
                return nums[i-1] + 1;
            }
            
        }
        //看尾
        return nums[nums.size()-1] + 1;

    }
};