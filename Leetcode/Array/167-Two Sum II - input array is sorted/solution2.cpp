#include <iostream>
#include <vector>

using namespace :: std;


class Solution2 {
public: 
    //利用对撞指针，时间复杂度为O（n）。
    vector<int> twoSum(vector<int>& numbers, int target) {

    int l = 0;
    int r = numbers.size()-1;
    while(l < r){
        if(numbers[l] + numbers[r] == target){
            return {l+1,r+1};
        }
        else if(numbers[l] + numbers[r] > target){
            r--;
        }
        else{
            l++;
        }
    }
    return{-1,-1};


    }
};