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
    //Hubbard Deletion
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        auto p = root;
        if(key < p->val) p->left = deleteNode(p->left, key);
        else if(key > p->val) p->right = deleteNode(p->right, key);
        else{
            if(p->right == nullptr) return p->left;
            if(p->left == nullptr) return p->right;
            auto t = p;
            p = min(t->right);
            p->right = deleteMin(t->right);
            p->left = t->left;
        }
        return p;
    }
    TreeNode* min(TreeNode* root){
        if(root == nullptr) return nullptr;
        if(root->left == nullptr) return root;
        return min(root->left);
    }
    TreeNode* deleteMin(TreeNode* root){
        if(root == nullptr) return nullptr;
        if(root->left == nullptr) return root->right;
        root->left = deleteMin(root->left);
        return root;
    }
};