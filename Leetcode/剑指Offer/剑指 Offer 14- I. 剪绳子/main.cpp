#include <iostream>
#include <vector>
using namespace ::std;
class Solution {
public:
    vector<int> record;

    int maxLong(int n){
        int res = -1;

        if(n == 2){
            return 1;

        }

        if(record[n] != -1){
            return record[n];
        }
        
        for(int i = 1; i <= n; i++){
            res = max(res, max(i * (n - i),i * maxLong(n-i)));
                
        }
        record[n] = res;
        

        return record[n];
    }

    int cuttingRope(int n) {
        record = vector<int>(n+1,-1);
        return maxLong(n);
    }
};