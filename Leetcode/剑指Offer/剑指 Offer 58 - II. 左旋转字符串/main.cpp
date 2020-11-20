#include <string>
using namespace ::std;
class Solution {
public:
    void reverseString(string &s){
        int l = 0;
        int r = s.size() - 1;
        while(l < r){
            swap(s[l],s[r]);
            l++;
            r--;
        }

    }
    string reverseLeftWords(string s, int n) {
        //最后的字符串 = （拿出去的字符串反转 + （原字符串反转之后删除后n位））的反转
        if(n == 0){
            return s;
        }

        string temp;
        for(int i = 0 ; i < n ; i ++){
            temp.push_back(s[i]);
        }

        reverseString(temp);

        reverseString(s);
        for(int i = 0; i < n; i++){
            s.pop_back();
        }
        s.insert(0,temp);
        reverseString(s);
        return s;
    }
};