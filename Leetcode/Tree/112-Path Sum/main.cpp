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
    //递归
    bool hasPathSum(TreeNode* root, int sum) {
        //如果给的根节点是空，那么就找不到任何路径
        if(root == nullptr){
            return false;
        }
        //如果一个节点的左节点和右节点都为空，那么说明他是个叶子节点
        if(root->left == nullptr && root->right == nullptr ){
            return root->val == sum;
        }
        //左树和右树只要有一个找到了符合要求的路径，就返回true
        if(hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val))
        {
            return true;
        }





        return false;
        
    }
};