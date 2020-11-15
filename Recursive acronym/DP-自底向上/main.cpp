#include <iostream>
#include <ctime>
#include <vector>

using namespace :: std;
//动态规划：将问题拆成若干个子问题，保存子问题的答案，使得每个子问题只运算一次。

long long fib(int n){

    vector<long long> memo(n+1,-1);
    memo[0] = 0;
    memo[1] = 1;
    for(int i = 2; i <= n; i++){
        memo[i] = memo[i-1] + memo[i-2];
    }

    return memo[n];


}

int main(){

    int n = 10;
    clock_t startTime = clock();
 
    long long res = fib(n);

    clock_t endTime = clock();
    cout<< "Run tume " << ":" << double(endTime - startTime)/ CLOCKS_PER_SEC << "s" <<endl;
    cout<<"result = "<<res;
}