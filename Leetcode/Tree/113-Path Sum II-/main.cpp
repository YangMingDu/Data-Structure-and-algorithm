#include <iostream>
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
    //回溯加递归
    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        vector<vector<int>> res;
        if(!root)
            return res;

        vector<int> tres;
        dfs(root, tres, 0, sum, res);
        return res;
    }

private:
    void dfs(TreeNode* node, vector<int>& tres, int tsum,
             int sum, vector<vector<int>>& res){
        //先将当前的节点推入数组
        tres.push_back(node->val);
        tsum += node->val;
        //如果是叶子节点
        if(!node->left && !node->right){
            //如果叶子节点符合要求
            if(tsum == sum)
                //将这个数组推入结果数组
                res.push_back(tres);
        }
        //不是叶子节点
        else {
            if (node->left)
                dfs(node->left, tres, tsum, sum, res);

            if (node->right)
                dfs(node->right, tres, tsum, sum, res);
        }
        //这条路径不对的话，就把加入的节点删除。
        tres.pop_back();
        return;
    }
};
