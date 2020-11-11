#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    //检查是否重复
    vector<bool> used;

    void backTravel(int index,vector<int>& nums,vector<int> &p){

        if(index == nums.size()){
            res.push_back(p);
            return;
        }

        for(int i = 0 ; i < nums.size() ; i++){
            if(!used[i]){
                if( i > 0 && nums[i] == nums[i-1] && !used[i-1] ){
                    continue;
                }
                p.push_back(nums[i]);
                used[i] = true;
                backTravel(index + 1,nums,p);
                //回溯步骤，维护used，并且踢掉之前的元素
                used[i] = false;
                p.pop_back();
                

            }
        }

    }







    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<int> p;
        res.clear();
        if(nums.size() == 0){
            return res;
        }
        sort(nums.begin(),nums.end());
        used = vector<bool>(nums.size(),false);
        backTravel(0,nums,p);
        return res;


    }
};