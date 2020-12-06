#include <vector>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr)
            return nullptr;
        // vector中保存了中序遍历的结果
        vector<Node*> nodes;

        inorderTraverse(root, nodes);

        int n = nodes.size();
        for (int i = 0; i < n; i++) {
            // (i + n - 1) % n 避免第一个结点的index 0 减1出现负数
            nodes[i]->left = nodes[(i + n - 1) % n];
            // (i + 1) % n 是为了避免最后一个结点 + 1越界
            nodes[i]->right = nodes[(i + 1) % n];
        }
        return nodes[0];
    }

    void inorderTraverse(Node *root, vector<Node *> &nodes) {
        if (root == NULL)
            return;
        inorderTraverse(root->left, nodes);
        nodes.push_back(root);
        inorderTraverse(root->right, nodes);
    }
};

