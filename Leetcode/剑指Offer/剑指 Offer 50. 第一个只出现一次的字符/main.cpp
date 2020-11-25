#include<unordered_map>
#include<string>
using namespace ::std;
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> t;
        for(char c: s) t[c]++;
        //这里遍历的是s，所以不需要在map中记住顺序！
        for(char c: s)
            if(t[c]== 1) return c;
        return ' ';
    }
};