#include <iostream>
#include <vector>

using namespace :: std;

class Solution {
public:
    //利用对撞指针解决问题
    void reverseString(vector<char>& s) {
        char tmp;
        int l = 0;
        int r = s.size() - 1;
        while(l < r){

            tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;

            l++;
            r--;
            
        }

    }
};