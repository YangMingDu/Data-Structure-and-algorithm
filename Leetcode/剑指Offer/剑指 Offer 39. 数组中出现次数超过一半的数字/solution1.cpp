#include<unordered_map>
#include<vector>
using namespace ::std;
class Solution {
public:
    //利用哈希表
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> record;
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        for(int i = 0; i < n;i++){
            record[nums[i]] ++;
            if(record[nums[i]] >= n/2 + 1){
                return nums[i];
            }
        }

        return -1;
    }
};