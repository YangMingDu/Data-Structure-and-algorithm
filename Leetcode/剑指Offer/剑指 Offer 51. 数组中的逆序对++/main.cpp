#include <vector>
using namespace ::std;
class Solution {
public:
int res = 0;

int reversePairs(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    vector<int> temp(n);
    mergeSort(nums, temp, 0, nums.size()-1);
    return res;
}

void mergeSort(vector<int>& nums, vector<int>& temp, int l, int r) {
    if(l >= r) return;
    int mid = (l + r) / 2;
    mergeSort(nums, temp, l, mid);
    mergeSort(nums, temp, mid+1, r);
    merge(nums, temp, l, mid, mid+1, r);
}

void merge(vector<int>& nums, vector<int>& temp, int l1, int l2, int r1, int r2) {
    int i = l1, j = r1, pos = l1;

    while(i <= l2 && j <= r2) {
        if(nums[i] <= nums[j]) {
            temp[pos++] = nums[i++];
        }else {
            res += l2-i+1;  //唯一改动
            temp[pos++] = nums[j++];
        }
    }

    while(i <= l2) {
        //res += r2-r1+1;
        temp[pos++] = nums[i++];
    }

    while(j <= r2) {
        temp[pos++] = nums[j++];
    }

    for(int i=l1;i<=r2;i++) nums[i] = temp[i];
}
};