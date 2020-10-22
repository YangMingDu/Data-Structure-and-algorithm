#include <iostream>
#include <string>

using namespace :: std;


class Solution {
public:
    //利用滑动窗口，用freq记录不同字符出现的频率。
    int lengthOfLongestSubstring(string s) {
        
        int freq[256] = {0};
        int l = 0;
        int r = -1;
        int res = 0;

        while(l < s.size()){
            //发现字符出现频率等于0，则表示之前没有同样的字符，那么将右边界右移之后将右端出现的字符频率加一。
            if(r+1 < s.size() && freq[s[r+1]] == 0){
                r++;
                freq[s[r]] ++;
            }
            //发现字符出现频率不等于0，则表示之前已经有同样的字符，即为重复字符，那么先将左端的字符出现频率减去，之后左边界右移。
            else{
                freq[s[l]]--;
                l++;
            }
            //记录最长的字符。
            res = max( res, r-l+1);
        }
        return res;

    }
};