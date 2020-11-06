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
    //层序遍历，将所有左叶子节点的值加在一块。
    bool isLeafNode(TreeNode* node) {
        return !node->left && !node->right;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                if (isLeafNode(node->left)) {
                    ans += node->left->val;
                }
                else {
                    q.push(node->left);
                }
            }
            if (node->right) {
                if (!isLeafNode(node->right)) {
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};

