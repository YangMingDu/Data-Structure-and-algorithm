#include <iostream>
#include <vector>
using namespace ::std;
class Solution {
public:


    int cuttingRope(int n) {
        int res = -1;
        if(n <= 3)
            return n - 1;
        vector<int> record(n+1,-1);
        record[1] = 1;
        record[2] = 2;
        record[3] = 3;
        for(int i = 4; i <= n; i++){
            for(int j = 1 ; j < i; j++){
                record[i] = max(record[i],record[j] * record[i-j]);
            }
        }
        return record[n];
        

    }
};