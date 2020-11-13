#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    //总体来说和47题有些类似
    void backtracking(vector<int>& nums,int startIndex, vector<bool>& used){
        result.push_back(path);
        if(startIndex==nums.size()){
            return;
        }
        for(int i = startIndex;i<nums.size();i++){
            //去重
            if(i>0 && nums[i] == nums[i-1] && !used[i-1]){
                continue;
            }
            path.push_back(nums[i]);
            used[i]=true;
            backtracking(nums,i+1,used);
            path.pop_back();
            used[i]=false;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> visited(nums.size(),false);
        sort(nums.begin(),nums.end());
        backtracking(nums,0,visited);
        return result;
        
    }
};