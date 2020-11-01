#include <vector>
#include <iostream>
using namespace ::std;
class Solution {
public:
    vector<int> memo;
    int max3(int a, int b, int c){
        return max(a,max(b,c));
    }

    int breakInt(int n){

        if(n == 1){
            return 0;
        }

        if(memo[n] != -1){
            return memo[n];
        }

        int res = -1;


        //至少分一次
        for(int i = 1 ; i <= n - 1 ; i ++){
            //因为breakint至少分割一次，所以要考虑当不再分割时是最大值的情况，i*（n-i）
            res = max3(res,i*(n-i),i*breakInt(n-i));
            memo[n] = res;
        }
        return memo[n];

    }

    int integerBreak(int n) {
        memo = vector<int>(n+1,-1);
        int res = breakInt(n);
        return res;
    }
};