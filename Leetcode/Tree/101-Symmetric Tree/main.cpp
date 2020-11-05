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
    //递归法
    bool isSymmetricLR(TreeNode* left,TreeNode* right){
        if(left== nullptr && right == nullptr){
            return true;
        }
        if(!left || !right){
            return false;
        }
        //需要左子树的右子树和右子树的左子树相等并且左子树的左子树与右子树的右子树相等。
        if(left && right && left->val == right->val){
            return isSymmetricLR(left->left, right->right) && isSymmetricLR(left->right, right->left);
        }

        return false;
    } 
    bool isSymmetric(TreeNode* root) {

        if(root == nullptr){
            return true;
        }

        return isSymmetricLR(root->left,root->right);
        
    }
};