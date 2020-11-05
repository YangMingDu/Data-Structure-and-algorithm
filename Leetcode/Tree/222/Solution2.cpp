#include <iostream>
#include <queue>

using namespace::std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 class Solution {
public:
    //利用迭代加上完全二叉树的特性
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int pos = 0;
        queue<TreeNode*> q;
        TreeNode* p;

        q.push(root);
        while(!q.empty()){
            p = q.front();
            q.pop();
            pos++;
            //当遍历到唯一一个没有任何子树或没有左子树的节点时，如果这个节点没有孩子，那么所有的节点数=这个节点的序号(pos)的2pos-1个，如果只有左节点，就是2pos个
            if(!p -> left && !p -> right){
                return pos * 2 - 1;
            }else if(p -> left && !p -> right){
                return pos * 2;
            }
            //节点序号从左到右上升
            q.push(p -> left);
            q.push(p -> right);
        }
        return 0;   
    }
};