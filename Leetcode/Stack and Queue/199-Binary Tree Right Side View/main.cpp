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
    vector<int> rightSideView(TreeNode* root) {

	vector<int> res;
	if (!root) return res;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		int size = q.size();
		res.push_back(q.front()->val);
		while (size--)
		{   
            //这样操作的话就只会剩下最右边的节点，他pop了其他的节点。
			TreeNode* temp = q.front();
			q.pop();
			if (temp->right) q.push(temp->right);
			if (temp->left) q.push(temp->left);

		}
	}
	return res;


    }
};