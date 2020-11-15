#include <vector>
using namespace ::std;
class Solution {
public:
    //记忆化搜索
    vector<long long> record;
    long long fibCal(int n){

        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }

        if(record[n] == -1){
            record[n] = (fibCal(n-1) + fibCal(n-2))%1000000007;
        }      

        return record[n];


    }
    long long fib(int n) {   
    record = vector<long long>(n+1,-1);
    return fibCal(n);
    }
};