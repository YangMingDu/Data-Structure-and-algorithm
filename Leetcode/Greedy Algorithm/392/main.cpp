#include <iostream>
#include <algorithm>
#include <vector>

using namespace :: std;

class Solution {
public:
    bool isSubsequence(string s, string t) {

        int l_s = s.length();
        int l_t = t.length();
        int i = 0;
        int j = 0;

        while (i < l_s && j < l_t) {

            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == l_s;
    }
};



int main(){

    return 0;
}