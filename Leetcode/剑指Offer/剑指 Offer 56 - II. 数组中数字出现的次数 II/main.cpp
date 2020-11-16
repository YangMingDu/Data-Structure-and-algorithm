#include <vector>
#include <unordered_map>
using namespace ::std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    unordered_map<int,int> record;

    for(int i = 0 ; i < nums.size(); i++){
        record[nums[i]] ++;
    } 

    for(auto &v : record){
        if(v.second == 1){
            return v.first;
        }
    }
    return 0;
    }
};