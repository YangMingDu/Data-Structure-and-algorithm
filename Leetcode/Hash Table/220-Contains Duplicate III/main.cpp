#include <iostream>
#include <vector>
#include <set>
using namespace :: std;
class Solution {
public:
    //利用set的lower_bound函数寻找set中大于等于nums[i]-t的值，再看这个值是否小于等于nums[i]+t
    //需要注意整形溢出的问题
    //record.lower_bound也是指针，所以求值需要加*
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

        set<long long> record;

        for(int i = 0; i < nums.size(); i++){
            if(record.lower_bound((long long)nums[i]-(long long)t) != record.end() && *record.lower_bound((long long)nums[i]-(long long)t) <= ((long long)nums[i] + (long long)t)){
                return true;
            }

            record.insert(nums[i]);

            if(record.size() == k+1){
                record.erase(nums[i-k]);
            }

        }

        return false;

    }
};