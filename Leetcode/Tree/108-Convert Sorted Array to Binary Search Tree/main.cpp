#include <iostream>
#include <vector>
using namespace::std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return help(nums, 0, nums.size() - 1);
    }
    //利用二分法
    TreeNode* help(vector<int>& nums, int l, int r) {
        if (r < l) return nullptr;
        int mid = l + (r-l)/2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = help(nums, l, mid - 1);
        root->right = help(nums, mid + 1, r);
        return root;
    }
};