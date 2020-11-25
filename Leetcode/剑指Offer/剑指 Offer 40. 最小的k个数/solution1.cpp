#include<vector>
#include<algorithm>
using namespace ::std;
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        sort(arr.begin(), arr.end());
        for(int i = 0 ; i < k; i++){
            res.push_back(arr[i]);
        }
        return res;
    }
};