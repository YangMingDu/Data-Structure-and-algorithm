#include <vector>
#include <unordered_map>
using namespace ::std;
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        unordered_map<int,int> record;
        vector<int> res;

        for(int i = 0 ; i < nums.size(); i++){
            record[nums[i]] ++;
        } 

        for(auto &v : record){
            if(v.second == 1){
                res.push_back(v.first);
            }
        }
        return res;

    }
};