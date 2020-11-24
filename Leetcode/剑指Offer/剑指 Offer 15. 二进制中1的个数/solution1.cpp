#include<iostream>
using namespace ::std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
    int cnt = 0;
    for (int i = 0; i < 32; i++) {
        if ((n >> i) & 0x00000001) {
            cnt++;
        }
    }
    return cnt;        
    }
};