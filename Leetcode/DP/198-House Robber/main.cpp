#include <vector>
#include <iostream>

using namespace :: std;
class Solution {
public:
    //记忆化搜索

    vector<int> memo;
    //考虑抢劫nums[index...nums.size()]这个范围的所有房子
    int tryRob(vector<int>& nums,int index){

        if(index >= nums.size()){
            return 0;
        }

        if(memo[index] != -1){
            return memo[index];
        }
        
        int res = 0;

        for(int i = index ; i < nums.size() ; i++){
            res = max(res , nums[i] + tryRob(nums,i+2));
        }

        memo[index] = res;

        return res;

        
    }



    int rob(vector<int>& nums) {
        memo = vector<int>(nums.size(), -1);
        return tryRob(nums,0);

    }
};