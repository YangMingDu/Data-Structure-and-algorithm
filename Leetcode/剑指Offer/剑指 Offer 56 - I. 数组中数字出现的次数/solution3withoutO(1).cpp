#include <vector>
#include <unordered_map>
using namespace ::std;
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        unordered_map<int,int> record;
        vector<int> res;

        for(int i = 0 ; i < nums.size(); i++){
            if(record.find(nums[i]) != record.end()){
                record.erase(nums[i]);
                continue;
            }
            record[nums[i]] ++;
        } 

        for(auto &v : record){
            res.push_back(v.first);
        }
        return res;

    }
};