#include <iostream>

#include <string>

using namespace ::std;
class Solution {
public:
    //建立新的string
    string replaceSpace(string s) {
        string res;
        for(int i = 0; i < s.size() ; i++){
            if(s[i] == ' '){
                res += "%20";
            }
            else{
                res += s[i];
            }
        }
        return res;
    }
};