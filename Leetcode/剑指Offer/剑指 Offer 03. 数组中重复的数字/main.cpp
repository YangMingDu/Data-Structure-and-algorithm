#include <iostream>
#include <unordered_map>
#include <vector>

using namespace ::std;
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        if (nums.size() == 0){
            return -1;
        }
        unordered_map<int,int> record;
        for(int i = 0 ; i < nums.size() ; i++){
            record[nums[i]]++;
            if(record[nums[i]] == 2 ){
                return nums[i];
            }
        }

        return -1;



    }
};