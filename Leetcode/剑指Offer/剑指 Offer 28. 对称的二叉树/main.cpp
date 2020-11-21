#include<iostream>
using namespace :: std;
struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:

    bool leftEqualRight(TreeNode* left,TreeNode* right){
        if(left == nullptr && right == nullptr){
            return true;
        }
        if(left == nullptr || right == nullptr){
            return false;
        }

        if(left->val == right->val){
            return leftEqualRight(left->left,right->right) && leftEqualRight(left->right,right->left);
        }

        return false;
    }



    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        return leftEqualRight(root->left,root->right);
    }
};