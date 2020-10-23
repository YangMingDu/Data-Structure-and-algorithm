#include <iostream>
#include <string>
#include <unordered_map>

using namespace :: std;
class Solution {
public:
    //利用双哈希表解决问题
    bool isAnagram(string s, string t) {
        //考虑s，t都为空的情况。
        if(s.size() == 0 && t.size() == 0){
            return true;
        }
        //键为char型，值为int型
        unordered_map<char,int> record;
        unordered_map<char,int> recordResult;
        for(int i = 0 ; i < s.size(); i ++){
            record[s[i]] ++;
        }
        for(int i = 0 ; i < t.size(); i ++){
            recordResult[t[i]] ++;
        }

        if(record == recordResult){
            return true;
        }
        else{
            return false;
        }

    }
};