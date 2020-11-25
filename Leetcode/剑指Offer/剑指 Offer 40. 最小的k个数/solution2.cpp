#include<vector>
#include <queue>
using namespace ::std;
class Solution {
public:

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        //利用优先队列
        vector<int>vec(k, 0);
        if (k == 0) { // 排除 0 的情况
            return vec;
        }
        priority_queue<int> Q;
        //最大堆
        for (int i = 0; i < k; ++i) {
            Q.push(arr[i]);
        }
        for (int i = k; i < (int)arr.size(); ++i) {
            //只要发现比首元素小，那么就pop掉
            //将新的数push进去合适的位置（自动）
            if (Q.top() > arr[i]) {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            //最后遍历
            vec[i] = Q.top();
            Q.pop();
        }
        return vec;
    }
};
