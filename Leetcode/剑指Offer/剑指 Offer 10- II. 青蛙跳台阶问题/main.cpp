#include <iostream>
#include <vector>
using namespace :: std;
class Solution {
public:
    vector<int> record;

    int numWays(int n){
        record = vector<int>(n+1,-1);
        if(n <= 1 ){
            return 1;
        }
        record[0] = 1;
        record[1] = 1;
        record[2] = 2;
        
        for(int i = 2; i <= n; i++){
            record[i] = (record[i - 1] + record[i - 2])%1000000007;
        }


        return record[n];
        
    }

};