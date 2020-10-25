#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace :: std;

class Solution {
public:
    //利用哈希表记录字符出现频率，之后进行排序。
    string frequencySort(string s) {
        unordered_map<char, int> record;
        vector<pair<char, int>> recordVec;
        for(int i = 0 ; i < s.size(); i ++){
            record[s[i]] ++;
        }
        
        for (const auto &m : record) {
            recordVec.push_back(m);
        }

        sort(recordVec.begin(), recordVec.end(), [](const pair<char, int> &p1, const pair<char, int> &p2) { return p1.second > p2.second; });

        string res;
        for (const auto &v : recordVec) {
            res += string(v.second, v.first);
        }
        return res;
    }
};

