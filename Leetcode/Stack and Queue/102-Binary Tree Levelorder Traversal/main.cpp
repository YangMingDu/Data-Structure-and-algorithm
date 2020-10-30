#include<queue>
#include<string>
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
    //经典二叉树层序遍历
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> res;

        if(root == nullptr){
            return res;
        }
        //建立队列，包含一个节点和它对应的层数
        queue<pair<TreeNode*,int>> q;
        //推入第一个元素，第0层的根节点
        q.push(make_pair(root, 0));

        while(!q.empty()){

            //每次推出一个任务（元素）
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            //如果层数等于res的size，也就是二维数组中的数组的个数（每层一个数组），就说明还不存在这一层，需要推入新的数组。例如level = 2也就是第三层，res的size=2说明只有两层的数组，需要建立新的数组来表示第三层。
            if(level == res.size()){
                res.push_back(vector<int>());
            }
            //将节点的值推入他相应层数的数组中。
            res[level].push_back(node->val);

            
            //如果有左右孩子，推入队列，但是层数+1
            if(node->left){
                q.push(make_pair(node->left,level + 1));
            }

            if(node->right){
                q.push(make_pair(node->right,level + 1));
            }




        }



        return res;
        
    }
};