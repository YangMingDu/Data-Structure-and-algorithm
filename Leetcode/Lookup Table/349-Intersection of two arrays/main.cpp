#include <iostream>
#include <vector>
#include <set>

using namespace :: std;
class Solution {
public:
    //Set使用方式：有insert插入操作，find寻找操作，erase删除操作。且set每种元素只能存储一次
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        /*set<int> record;
        for( int i = 0 ; i < nums1.size() ; i ++){
            record.insert( nums1[i] );
        }*/

        //使用set内置的构造函数，将nums1每种元素都放到record这个set里面
        //set底层为平衡二叉树，时间复杂度为O（logn）
        //如果改为unordered_set，底层为哈希表，时间复杂度为O（1）
        set<int> record(nums1.begin(),nums2.end());
        
        set<int> resultSet;
        for( int i = 0 ; i < nums2.size() ; i ++){
            //C++中set中find函数，找不找得到该元素由它等不等于set的end（）来决定，如果等于的话就是不存在，不等于的话就是存在  
           if( record.find(nums2[i]) != record.end()  ){
               resultSet.insert( nums2[i]);
           }
        }

        /*vector<int> resultSetVector;
        for (set<int>::iterator iter = resultSet.begin() ; iter != resultSet.end() ; iter ++){
            resultSetVector.push_back(*iter);
        }*/
        
        return vector<int>(resultSet.begin(),resultSet.end());
    }
};