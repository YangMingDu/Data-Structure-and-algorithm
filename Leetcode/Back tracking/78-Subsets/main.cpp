#include <iostream>
#include <vector>

using namespace ::std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    void combinationSumCore(vector<int>& candidates,vector<int>& tmp,int begin,int k){
        if(tmp.size() == k){
            res.push_back(tmp);
            return;
        }
        
        for(int i=begin; i<candidates.size(); ++i){
                //去重
                if(i > begin && candidates[i] == candidates[i-1] ){
                    continue;
                }
                tmp.push_back(candidates[i]);
                combinationSumCore(candidates,tmp,i+1,k);
                tmp.pop_back();


            }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        for(int k = 0 ; k <= nums.size(); k++){
        combinationSumCore(nums,tmp, 0, k);
    }
    return res;
    }
};