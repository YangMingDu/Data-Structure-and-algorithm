#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace :: std;
class Solution {
public:
    //键值对应，键为string，因为字母异位词之间string的值相等，值为同一种字母异位词组成的vector。
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> map;
        for(const string& s: strs){
            string key = s;
            sort(key.begin(), key.end());
            map[key].push_back(s);
        }

        vector<vector<string>> res;
        for(const auto& p: map)
            res.push_back(p.second);
        return res;
    }
};