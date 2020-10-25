#include <iostream>
#include <vector>
#include <unordered_map>
using namespace :: std;

class Solution {
public:
    //利用哈希表解决问题，为了避免重复的元素导致覆盖，我们不先将数组的全部元素存入哈希表，而是将依次在哈希表里面寻找目标值，如果没找到的话说明不成功，此时再将新的元素加入到哈希表中。
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> record;
        int index = 0;
        for(int i = 0 ; i < nums.size() ; i ++){
            int complement = target - nums[i];
            //如果没找到符合题目的值，再将这个元素存入哈希表中。
            if(record.find( complement) != record.end()){
                int res[2] = {i, record[complement]};
                return vector<int>(res,res+2);
            }
            record[nums[i]] = i;
        }
        return {0};

    }
};