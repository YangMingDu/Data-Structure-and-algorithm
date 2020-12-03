#include<iostream>
#include<queue>

using namespace :: std;


struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    //层序遍历
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if(root == nullptr){
            return res;
        }
        queue<TreeNode*> record;
        record.push(root);

        while(record.size() != 0){

            int count = record.size();

            while(count != 0){
                TreeNode* cur = record.front();
                int val = cur->val;
                res.push_back(val);
                record.pop();
                if(cur->left != nullptr){
                    record.push(cur->left);
                }
                if(cur->right != nullptr){
                    record.push(cur->right);
                }

                count --;
            }




        }

        return res;

    }
};