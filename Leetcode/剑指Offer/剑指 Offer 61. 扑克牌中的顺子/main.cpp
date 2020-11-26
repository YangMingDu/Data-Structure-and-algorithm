#include<vector>
#include<algorithm>
#include<queue>
using namespace ::std;
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        queue<int> record;
        int min;
        int max;
        for(int i = 0 ; i < nums.size() - 1; i++){
            //如果有非0重复一定不是顺子
            if(nums[i] == nums[i + 1] && nums[i] != 0){
                return false;
            }
            //将不等于0的数入列
            if(nums[i] != 0){
                record.push(nums[i]);
            }
        }
        //队列的第一个元素也就是最小的不等于0的数
        //最大的数减去最小的非0数如果小于等于4那么一定是顺子
        if(nums[4] - record.front() <= 4){
            return true;
        }

        return false;
    }
};