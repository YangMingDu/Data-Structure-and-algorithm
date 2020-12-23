#include <string>
#include <unordered_map>
using namespace :: std;
class Solution {
public:
    bool canPermutePalindrome(string s) {

        unordered_map<char,int> record;
        for(auto i : s){
            record[i]++;
            if(record[i] >= 2){
                record[i] = record[i] % 2;
            }
        }

        int count = 0;

        for(auto i : record){
            if(i.second == 1 ){
                count ++;
            }
        }

        if(count > 1){
            return false;
        }

        return true;
        

    }
};