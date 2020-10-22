#include <iostream>
#include <vector>

using namespace :: std;

class Solution {
public:
    //利用固定长度的滑动窗口解决问题
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size())
            return {};
        int l = 0, r = -1;
        vector<int> freq_s(26, 0), freq_p(26, 0), res;
        // 初始化代码值，初始化freq_s的长度和p的长度一样
        for( int i = 0 ; i < p.size() ; i++ ){
            freq_p[p[i] - 'a' ]++;
            r ++;
            freq_s[s[r] - 'a' ]++;
        }
        if ( freq_s == freq_p )
            res.push_back( l );
        // 固定长度的滑动窗口，依次向右移动
        while( r < s.size()-1 ){
            r++;
            freq_s[s[r] - 'a' ]++;
            freq_s[s[l] - 'a' ]--;
            l++;
            if ( freq_s == freq_p )
                res.push_back( l );
        }
        return res;
    }
};