#include <iostream>
#include <string>

using namespace :: std;

class Solution {
public:
    //先判断是否为元音，然后利用对撞指针解决问题。
    bool isVowels(char s) {
        return (s == 'a' || s == 'A' || s == 'e' || s == 'E' || s == 'i' || s == 'I' || s == 'o' || s == 'O' || s == 'u' || s == 'U') ;
    }
    
    string reverseVowels(string s) {
        int l = 0; 
        int r = s.length() - 1;
        while (l < r) {
             if (! isVowels(s[l])) {
                 l ++;
                } 
             if (! isVowels(s[r])) {
                 r --; 
                } 
            if(isVowels(s[l]) && isVowels(s[r])){
                swap(s[l++],s[r--]);
            }


        } 
        return s;
    }



};