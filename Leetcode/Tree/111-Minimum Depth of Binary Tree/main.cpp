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
    int minDepth(TreeNode* root) {

        if(root == NULL){

            return 0;

        }

        
        return (root->left && root->right) ? 1+min(minDepth(root->left),minDepth(root->right)):1+minDepth(root->left)+minDepth(root->right);
    }
};