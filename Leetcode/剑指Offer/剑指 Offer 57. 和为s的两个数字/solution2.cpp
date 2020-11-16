#include <unordered_set>
#include <vector>
using namespace ::std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //字典
        unordered_set<int> record;
        vector<int> res;
        for(int i = 0 ; i < nums.size(); i++){
            record.insert(nums[i]);
        }
        for(int j = 0; j < nums.size(); j++){
            int findTarget = target - nums[j];
            if(record.find(findTarget) != record.end()){
                res.push_back(nums[j]);
                res.push_back(findTarget);
                break;
            }
        }

        return res;
    }
};