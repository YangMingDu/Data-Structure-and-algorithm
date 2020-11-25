#include<vector>
using namespace ::std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int max = INT_MIN;
        int numsSize = int(nums.size());
        for (int i = 0; i < numsSize; i++)
        {
            int sum = 0;
            for (int j = i; j < numsSize; j++)
            {
                sum += nums[j];
                if (sum > max)
                {
                    max = sum;
                }
            }
        }

        return max;
    }
};
