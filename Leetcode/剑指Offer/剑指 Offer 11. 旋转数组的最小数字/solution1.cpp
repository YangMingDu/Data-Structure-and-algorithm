#include <iostream>
#include <vector>
#include <algorithm>
using namespace :: std;
class Solution {
public:
    //直接排序，输出最小的
    int minArray(vector<int>& numbers) {
        sort(numbers.begin(),numbers.end());
        return numbers[0];
    }
};