#include <iostream>
#include <vector>

using namespace :: std;
class Solution {
public:
    //利用对撞指针解决问题，比较前后两个字符是否相等
    bool isPalindrome(string s) {
        string aux;
        for (char ch: s) {
            if (isalnum(ch)) {
                aux += tolower(ch);
            }
        }
        int size = aux.size();
        int l = 0;
        int r = size - 1;
        while (l < r) {

           if (aux[l] != aux[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
