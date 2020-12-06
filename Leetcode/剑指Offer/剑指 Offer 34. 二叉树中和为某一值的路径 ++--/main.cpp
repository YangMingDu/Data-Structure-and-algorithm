#include<iostream>
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
    vector<vector<int>> res;
    vector<int> temp;

    void dfs(TreeNode* root,int target){
        if(root == nullptr){
            return;
        }
        temp.push_back(root->val);
        target = target - root->val;
        if(target == 0 && root->left == nullptr && root->right == nullptr){
            res.push_back(temp);
        } 
        else{
            dfs(root->left,target);
            dfs(root->right,target);
        }

        temp.pop_back();
        target += root->val;


    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        dfs(root,sum);
        return res;
    }
};