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

    int sumPath(TreeNode* root, int sum){
        //如果给出的根节点是0那么就直接返回0
        if(root == nullptr)
            return 0;
        //如果找到了叶子节点
        if (root->left == nullptr && root->right == nullptr)
            return 10*sum + root->val;
        //如果不是叶子节点，那么就将上一个节点的数字乘10再加上本节点的值
        return sumPath(root->left, 10*sum + root->val) + sumPath(root->right, 10*sum + root->val);
            
    }
    int sumNumbers(TreeNode* root) {
        return sumPath(root, 0);
    }
};