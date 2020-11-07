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
    int pathSum(TreeNode* root, int sum) {
        //输入根节点为null，直接返回0
        if(root == nullptr){
            return 0;
        }

        //当前节点找到符合题意的路径
        int res = findPath(root , sum);

        //找到当前节点的左孩子或右孩子符合的路径。并递归。
        res += pathSum(root->left, sum);
        res += pathSum(root->right, sum);

        return res;



        
    }

private:
    int findPath(TreeNode* node, int num){

        //直到找到空节点
        if(node == nullptr){
            return 0;
        }

        int res = 0;
        //每找到一个符合题意的路径，res+1；
        if(node->val == num){
            res += 1;
        }

        //由于有负数，所以一条路径之后可能还有更长的路径符合题意。
        //所以在此节点的左右子树中继续寻找，直到底（null）；
        res += findPath(node->left, num - node->val);
        res += findPath(node->right, num - node->val);

        return res;

    }
};