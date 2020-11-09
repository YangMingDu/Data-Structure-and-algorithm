#include <iostream>
#include <vector>
#include <unordered_map>
using namespace::std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    unordered_map<int,int> record;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //记录中序遍历的索引
        for(int i = 0; i < inorder.size(); i++){
            record[inorder[i]] = i;
        }
        //传入参数前序序列根节点，中序序列左边界，中序序列右边界，前序,中序，
        return treeBuilder(0,0,preorder.size()-1,preorder,inorder);
    }


    TreeNode* treeBuilder(int root,int left,int right,vector<int>& preorder, vector<int>& inorder){

        //递归终止条件：遍历到中序遍历第0个值
        if(left > right){
            return nullptr;
        }

        // 根节点在中序序列中的位置，用于划分左右子树的边界
        int rootIndex = record[preorder[root]];
        TreeNode* node = new TreeNode(preorder[root]);


         // 左子树在前序中的根节点位于：root+1,左子树在中序中的边界：[left,root-1]
        node->left = treeBuilder(root + 1,left,rootIndex - 1,preorder,inorder);
        // 右子树在前序中的根节点位于：根节点+左子树长度+1 = root+rootIndex-left+1
        node->right = treeBuilder(root+ rootIndex - left + 1,rootIndex + 1,right,preorder,inorder);

        return node;

    }
};