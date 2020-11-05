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
    //计算任意节点的高度
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } else {
            //任意节点的高度等于他最长的子树（无论左右），再加上自己
            return max(height(root->left), height(root->right)) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        } else {
            //相当于遍历所有节点，看看所有节点是不是他们的左子树和右子树的高度差小于等于1
            return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        }
    }
};