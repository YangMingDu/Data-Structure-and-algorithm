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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == nullptr){
            return nullptr;
        }

        //二叉搜索树中，如果p和q都在此节点的右侧，也就是说都大于这个节点
        //那么他们的共同祖先一定在此节点的右子树中，所以我们从他的右子树中递归寻找
        if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        //反之一样。
        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q);
        }




        //如果p和q分别在此节点的左右子树中，那么此节点就是最小共同祖先。
        return root;
    }
};