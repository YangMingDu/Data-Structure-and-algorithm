#include<vector>
#include<algorithm>
using namespace ::std;
class Solution {
public:
    //解法三：摩尔投票法
    //也可以理解成混战极限一换一，不同的两者一旦遇见就同归于尽，最后活下来的值都是相同的，即要求的结果
    //时间O(n)，空间O(1)
    int majorityElement(vector<int>& nums) {
        int res = 0, count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(count == 0){
                res = nums[i];
                count++;
            }
            else
                res==nums[i] ? count++:count--;
        }
        return res;
    }
};