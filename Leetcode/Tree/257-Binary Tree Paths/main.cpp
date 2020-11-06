#include <iostream>
#include <string>
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
    //递归
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> res;
        //如果给的是空节点，那么直接返回空
        if(root == nullptr){
            return res;
        }
        //终止条件：碰到叶子节点
        //返回当前叶子节点的值的字符串形式
        if(root -> left == nullptr && root->right == nullptr){
            res.push_back(to_string(root->val));
            return res;
        }

        //递归节点的左子树
        vector<string> leftS = binaryTreePaths(root->left);
        for (int i = 0 ; i < leftS.size() ; i ++){
            res.push_back(to_string(root->val) + "->" +leftS[i]);
        }
        //递归节点的右子树
        vector<string> rightS = binaryTreePaths(root->right);
        for (int i = 0 ; i < rightS.size() ; i ++){
            res.push_back(to_string(root->val) + "->" +rightS[i]);
        }

        return res;



    }
};