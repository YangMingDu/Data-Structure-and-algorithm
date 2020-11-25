#include<iostream>
#include<queue>
#include<vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }
        
        queue<TreeNode*> record;
        record.push(root);
        while(record.size() != 0){
            int count = record.size();
            vector<int> temp;
            //层层遍历弹出
            while(count != 0){
                TreeNode* cur = record.front();
                temp.push_back(cur->val);
                record.pop();
                if(cur->left != nullptr){
                    record.push(cur->left);
                }
                if(cur->right != nullptr){
                    record.push(cur->right);
                }
                count --;
            }
            res.push_back(temp);

        }

        return res;


    }
};