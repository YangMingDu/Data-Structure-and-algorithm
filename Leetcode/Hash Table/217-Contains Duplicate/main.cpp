#include <iostream>
#include <vector>
#include <unordered_set>
using namespace :: std;
class Solution {
public:
    //利用set特性，查重即可。
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> record;

        for(int i = 0; i < nums.size(); i++){
            if(record.find(nums[i]) != record.end()){
                return true;
            }

            record.insert(nums[i]);

        }

        return false;

    }
};