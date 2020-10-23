#include <iostream>
#include <string>
#include <unordered_map>

using namespace :: std;
class Solution {
    //将数字拆开并计算平方
    int calNum(int n){
        int ans = 0;
        while(n){
            ans += (n % 10)*(n % 10);
            n /= 10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        //设置哈希表，记录每个结果出现的个数
        unordered_map<int, bool> nums;
        while(1){
            int sum = calNum(n);
            //结果为1说明是快乐数
            if(sum == 1){
                return true;
            }
            //如果哈希表中已经有这个结果了，说明已经陷入循环，不是快乐数 
            else if(nums[sum]) {
                return false;
            }
            //将结果记入哈希表
            nums[sum] = true;
            n = sum;
        }
        return false;
    }
};