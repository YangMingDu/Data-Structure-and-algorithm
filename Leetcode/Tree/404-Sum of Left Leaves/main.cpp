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
    //递归方法
    int sumOfLeftLeaves(TreeNode* root) {
        
        
        if(root == nullptr){
            return 0;
        }
        //判断是否有左子树，如果没有，答案从右子树中寻找
        if(root->left == nullptr){
            return sumOfLeftLeaves(root->right);
        }
        //判断节点的左孩子是否为叶子节点
        if(root->left && root->left->left ==nullptr && root->left->right == nullptr){
            //如果是的话就把这个左叶子节点的值加入，并继续从右树寻找
            return root->left->val + sumOfLeftLeaves(root->right); 
        }

        //如果该节点既有左子树也有右子树，并且都不是叶子节点，那么就从两边寻找。
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);

    }
};