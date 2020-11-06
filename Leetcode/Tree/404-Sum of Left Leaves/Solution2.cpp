#include <iostream>

using namespace::std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    //dfs
    bool isLeafNode(TreeNode* node) {
        //判断是否为叶子节点
        return !node->left && !node->right;
    }

    int dfs(TreeNode* node) {
        int ans = 0;
        //如果该节点有左孩子节点，那么判断左孩子节点是否为叶子节点，如果是叶子节点，那么将左叶子节点值加入结果，否则继续从左树寻找。
        if (node->left) {
            ans += isLeafNode(node->left) ? node->left->val : dfs(node->left);
        }
        //如果该节点有右孩子节点，那么判断右孩子节点是否为叶子节点，如果不是叶子节点，那么从右树继续寻找。
        if (node->right && !isLeafNode(node->right)) {
            ans += dfs(node->right);
        }
        return ans;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return root ? dfs(root) : 0;
    }
};
