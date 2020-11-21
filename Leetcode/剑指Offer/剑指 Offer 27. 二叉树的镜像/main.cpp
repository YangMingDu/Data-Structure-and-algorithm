
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
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        root->left=mirrorTree(root->left);
        root->right=mirrorTree(root->right);
        swap(root->left,root->right);
        return root;
    }
};