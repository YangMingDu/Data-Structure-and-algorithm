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
    //中序遍历
    void inTravel(TreeNode* root,vector<int>& res){
        if(root == nullptr){
            return;
        }

        inTravel(root->left,res);
        res.push_back(root->val);
        inTravel(root->right,res);

    }

    int kthLargest(TreeNode* root, int k) {
        vector<int> res;
        inTravel(root,res);
        return res[res.size() -1 - (k-1)];
    }
};