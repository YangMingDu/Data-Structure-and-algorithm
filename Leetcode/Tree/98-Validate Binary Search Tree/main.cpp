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
    long long pre = LONG_MIN; // 用来记录前一个节点的值
    //利用中序遍历，因为二叉搜索树中序遍历为单调增。
    bool isValidBST(TreeNode* root) {
        if (root == NULL){
            return true;
        } 
        bool left = isValidBST(root->left);

        if (pre >= root->val){
            return false;
        }
        pre = root->val; // 记录前一个节点

        bool right = isValidBST(root->right);
        
        return left && right;
    }
};

