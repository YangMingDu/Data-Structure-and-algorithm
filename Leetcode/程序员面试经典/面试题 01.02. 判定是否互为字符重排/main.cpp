#include <string>
#include <unordered_map>
using namespace :: std;
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.size() != s2.size()){
            return false;
        }
        unordered_map<char,int> check;
        for(auto s : s1){
            check[s]++;
        }
        for(auto s : s2){
            check[s]--;
        }
        for(auto s : check){
            if(s.second != 0){
                return false;
            }
        }

        return true;
    }
};