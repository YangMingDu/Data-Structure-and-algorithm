#include <iostream>
#include <vector>
#include <unordered_set>
using namespace :: std;
class Solution {
public:
    //时间复杂度O（n）
    //空间复杂度O（k）
    //哈希表+滑动窗口解决问题，这个问题滑动窗口长度固定为k+1；保持里面有k个元素。
    bool containsNearbyDuplicate(vector<int>& nums, int k) {


        unordered_set<int> record;

        for(int i = 0; i < nums.size(); i++){
            //查重
            if(record.find(nums[i]) != record.end()){
                return true;
            }
            //如果没有重复的，就将这个元素插入
            record.insert(nums[i]);


            //保持record中有k个元素
            if(record.size() == k + 1){
                record.erase(nums[i - k]);
            }
        }
        //没找到重复的数

        return false;

    }
};