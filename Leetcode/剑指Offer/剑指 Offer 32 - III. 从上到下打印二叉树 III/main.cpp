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
        int level = 0;
        queue<TreeNode*> record;
        record.push(root);
        while(record.size() != 0){
            int count = record.size();
            vector<int> temp;
            while(count != 0){
                TreeNode* cur = record.front();
                record.pop();
                if(cur->left != nullptr){
                    record.push(cur->left);
                }
                if(cur->right != nullptr){
                    record.push(cur->right);
                }
                if(level % 2 == 0){
                    temp.push_back(cur->val);
                }
                else{
                    temp.insert(temp.begin(),cur->val);
                }
                count --;
            }
            level ++;
            res.push_back(temp);
            temp.clear();
        }
    
    return res;   
    }

};