#include <iostream>
#include <vector>
using namespace::std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    //中序遍历，将节点放入数组
    vector<int>Res;
    void inorder(TreeNode* root)
    {
        if(root==nullptr)
            return;
        inorder(root->left);
        Res.push_back(root->val);
        inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return Res[k-1];
        
    }
};