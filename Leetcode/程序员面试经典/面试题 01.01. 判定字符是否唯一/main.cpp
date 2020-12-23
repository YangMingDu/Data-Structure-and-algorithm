#include <string>
#include <unordered_map>
using namespace :: std;
class Solution {
public:
    bool isUnique(string astr) {
        if(astr.size() == 0){
            return true;
        }
        unordered_map<char,int> check;
        for(auto s : astr){
            check[s]++;
        }

        for(auto i : astr){
            if(check[i] > 1){
                return false;
            }

        }

        return true;
    }
};