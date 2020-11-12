#include <iostream>
#include <vector>

using namespace ::std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    void combinationSumCore(vector<int>& candidates, int target, vector<int>& tmp, int sum, int begin,int k){
        //终止条件为找到target
        if(sum == target && tmp.size() == k){
            res.push_back(tmp);
            return;
        }
        
        for(int i=begin; i<candidates.size(); ++i){
                //还可以继续寻找
            if(sum+candidates[i]<=target){
                //去重
                if(i > begin && candidates[i] == candidates[i-1] ){
                    continue;
                }
                tmp.push_back(candidates[i]);

                combinationSumCore(candidates, target, tmp, sum+candidates[i], i+1,k);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        //1-9当基础数组
        vector<int> candidates = {1,2,3,4,5,6,7,8,9};
        combinationSumCore(candidates,n,tmp, 0, 0,k);
        return res;

    }
};