#include <iostream>
#include <vector>

using namespace ::std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        
        combinationSumCore(candidates, target,tmp,0, 0);
        return res;
    }
    void combinationSumCore(vector<int>& candidates, int target, vector<int>& tmp, int sum, int begin){
        //终止条件为找到target
        if(sum == target){
            res.push_back(tmp);
            return;
        }
        
        for(int i=begin; i<candidates.size(); ++i){
                //还可以继续寻找
            if(sum+candidates[i]<=target){
                tmp.push_back(candidates[i]);
                //这里不传入i+1，因为可以重复，先找同一元素
                combinationSumCore(candidates, target, tmp, sum+candidates[i], i);
                tmp.pop_back();
            }
        }
    }
    
};