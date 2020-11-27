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
        if(root == NULL)
            return NULL;
        //如果根节点就是p或者q，返回根节点
        if(root == p || root == q)
            return root;
        //分别去左右子树里面找
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left && right)//p，q各在一边，说明当前的根就是最近共同祖先 
            return root;
        else if(left)//说明p，q都在左子树
            return left;
        else if(right)//说明p，q都在右子树
            return right;
        else
            return NULL;
        
    }
};