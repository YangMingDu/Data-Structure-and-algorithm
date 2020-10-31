#include <iostream>
#include <ctime>
#include <vector>

using namespace :: std;

int steps;
//记忆数组，利用记忆数组记录fib（n）的值，使得每个n只计算一次即可。
vector<long long> memo;
//在递归的基础上添加记忆。
long long fib(int n){
    steps ++;
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1; 
    }
    if (memo[n] == -1)
    {
        memo[n] = fib(n-1) + fib(n-2);
    }
    return memo[n];
    


}

int main(){

    int n = 50;
    memo = vector<long long>(n+1,-1);
    clock_t startTime = clock();
 
    long long res = fib(n);

    clock_t endTime = clock();
    cout<<"programme runs : "<< steps <<"times"<<endl;
    cout<< "Run tume " << ":" << double(endTime - startTime)/ CLOCKS_PER_SEC << "s" <<endl;
    cout<<"result = "<<res;
}