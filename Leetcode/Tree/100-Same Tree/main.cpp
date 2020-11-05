#include <iostream>

using namespace::std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        //如果都是空，那么相等，如果只有一个是空那么不等，如果值不相等那么不等
        if(p==nullptr && q==nullptr) return true;
        if(p==nullptr || q==nullptr) return false;
        if(p->val!=q->val) return false;

        
        //左右孩子一样，如果有一个不等，就是不相等。
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        
    }
};