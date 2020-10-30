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
    //逐层清空队列
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if (root == NULL)   return {};  
        queue<TreeNode*> q;     
        q.push(root);  

        int level=0;
        while (!q.empty()) 
        {  
            vector<int>temp;                //存放每一层的元素值
            int count=q.size();             //队列大小表示当前层数的元素个数
            while(count--)                  //count--逐个对该层元素进行处理
            {
                TreeNode *t=q.front();             
                q.pop();    
                if(level%2 ==0) 
                    temp.push_back(t->val);
                else
                    temp.insert(temp.begin(),t->val);
                if(t->left)     
                    q.push(t->left);
                if(t->right)    
                    q.push(t->right);
            }

            level++;
            res.push_back(temp);           //将当层元素的vector加入res中
        }
        return res;
        }
};

