#include <iostream>
#include <string>
#include <unordered_map>

using namespace :: std;

class Solution {
public:
//和290题一样，采取双map映射的方法解决问题。
    bool isIsomorphic(string s, string t) {

        unordered_map<char,char> StoT;
        unordered_map<char,char> TtoS;

        for(int i = 0; i < s.size() ; i ++){
            StoT[s[i]] = t[i];
            TtoS[t[i]] = s[i]; 
        }

        for(int i = 0 ; i < s.size(); i++){
            if(StoT[s[i]] != t[i] || TtoS[t[i]] != s[i] ){
                return false;
            }
        }

        return true;

        
    }
};