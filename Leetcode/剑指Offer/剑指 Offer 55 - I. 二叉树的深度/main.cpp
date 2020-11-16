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
    int maxDepth(TreeNode* root) {
        int resLeft = 0;
        int resRight = 0;
        if(root == nullptr){
            return 0;
        }
        //寻找左子树最大深度
        if(root->left){
            resLeft = maxDepth(root->left);
        }
        //寻找右子树最大深度
        if(root->right){
            resRight = maxDepth(root->right);
        }
        //返回左右子树中深度大的深度加上自己+1
        return max(resLeft,resRight) + 1;
    }
};