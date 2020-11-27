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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){
            return nullptr;
        }

        //都在左树
        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        //都在右树
        else if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        else{
            return root;
        }


    }
};