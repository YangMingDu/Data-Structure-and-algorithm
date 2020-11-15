#include <iostream>
#include <vector>
#include <algorithm>
using namespace :: std;
class Solution {
public:
    //递增性质进一步思考，如果它本身就是递增的，未被旋转，第一个就是最小，
    //如果被旋转了，那么旋转后的数组第一个元素必定比最小的元素大，
    //只需要找出数组中第一个小于旋转后数组的第一个元素的数字即可
    int minArray(vector<int>& numbers) 

    {
        for(int i = 0 ; i < numbers.size(); i++){
            if(numbers[i] < numbers[0]){
                return numbers[i];
            }
        }
    return numbers[0];
    }
};