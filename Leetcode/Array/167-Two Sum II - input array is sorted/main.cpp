#include <iostream>
#include <vector>

using namespace :: std;


class Solution1 {
public:
    //利用二分查找，找到target-numbers[i]这个元素，这样遍历一遍加上二分查找，时间复杂度为O（nlogn）。
    vector<int> twoSum(vector<int>& numbers, int target) {

        int i;
        for(i = 0; i < numbers.size(); i++){
            int partner = target - numbers[i];
            int l = i + 1;
            int r = numbers.size() - 1;
            while(l <= r){
                int mid = l + (r-l)/2;
                if(numbers[mid] == partner){
                    return {i + 1,mid + 1};
                }
                else if(numbers[mid] < partner){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }           
        }

        return {-1,-1};

    }
};