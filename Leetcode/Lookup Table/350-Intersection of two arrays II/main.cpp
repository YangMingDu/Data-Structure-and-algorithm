#include <iostream>
#include <vector>
#include <map>

using namespace :: std;
class Solution {
public:
    //利用map键值对应解决问题
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        //数据是int型，出现的次数也是int型
        map<int,int> record;
        //遍历nums1，将其种类和频率都输入进map
        for(int i = 0 ; i < nums1.size(); i ++){
            record[nums1[i]] ++;
        }

        vector<int> resultVector;
        //遍历nums2，查看频率是否存在，如果存在说明是子集，输入进vector之后频率减1。
        for(int i = 0 ; i < nums2.size(); i ++){
            if(record[nums2[i]] > 0){
                resultVector.push_back(nums2[i]);
                record[nums2[i]] --;
            }
        }

        return resultVector;

    }
};