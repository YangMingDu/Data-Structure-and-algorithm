#include<stack>
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
 
struct Command{
    string s;//go print
    TreeNode* node;
    Command(string s,TreeNode *node):s(s), node(node){}
};

class Solution {
public:
    //二叉树前序遍历（非递归）
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> res;
        if(root == NULL){
            return res;
        }
        //建立命令栈，命令是字符串，go或者print
        stack<Command> stack;
        //压入第一个命令
        stack.push(Command("go",root));


        //直到执行完最后一个print命令
        //也就是说栈里所有的指令全部都执行完毕了。
        while(!stack.empty()){
        
        //读取指令
         Command command = stack.top();
         //栈出指令
         stack.pop();

        
         if(command.s == "go"){

             if(command.node->right){
                 stack.push(Command("go",command.node->right));
             }
            stack.push(Command("print",command.node));    
             if(command.node->left){
                 stack.push(Command("go",command.node->left));
             }

                  
         }
         //说明print指令，直接将节点的值push到结果里。
         else{
             res.push_back(command.node->val);
         }   


        }


        return res;

        
    }
};