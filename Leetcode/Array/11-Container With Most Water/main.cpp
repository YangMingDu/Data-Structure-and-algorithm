#include <iostream>
#include <vector>

using namespace :: std;
class Solution {
    //利用对撞指针，每次都移动相对矮的板，在所有得出的面积中取最大值。
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int res = 0;
        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            res = max(res, area);
            if (height[l] <= height[r]) {
                ++l;
            }
            else {
                --r;
            }
        }
        return res;
    }
};
