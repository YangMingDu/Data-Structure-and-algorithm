
#include<iostream>
#include<vector>

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
    bool dfs(TreeNode * root1,TreeNode * root2){
        if(!root2) return true;
        if(!root1) return false;
        if(root1->val != root2->val) return false;
        return dfs(root1->left,root2->left) && dfs(root1->right,root2->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A||!B) return false;
        //从根，左子树，右子树分别寻找
        return dfs(A,B)||isSubStructure(A->left,B)||isSubStructure(A->right,B);
    }
};