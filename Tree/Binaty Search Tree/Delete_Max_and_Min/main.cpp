#include <iostream>
#include <queue>
#include <cassert>
using namespace :: std;

template<typename Key , typename Value> 
class BST{

private:

    struct Node{
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key,Value value){
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }
    };

    Node *root;
    int count;

public:

    BST(){
        root = NULL;
        count = 0;
    }
    ~BST(){

        destroy( root );

    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }
    //插入（递归）
    void insert(Key key,Value value){

        root = insert(root,key,value);
    }
    
    void contain(Key key){

        return contain(root,key);
    }
    //如果返回Node*，则需要把Node结构体放到public上，但是这样封装不是很好，如果返回Value的话，value不能为空，也就是说用户必须先contain再search，这次返回为value*可以为空，也方便用户更改数据。
    Value* search(Key key){
        return search(root,key);
    }
    //前序遍历
    void preOrder(){
        preOrder(root);
    }
    //中序遍历
    void inOrder(){
        inOrder(root);
    }
    //后序遍历
    void postOrder(){
        postOrder(root);
    }

    //层序遍历
    void levelOrder(){

        queue<Node*> q;
        q.push(root);
        while(!q.empty()){

            Node *node = q.front();
            q.pop();

            cout<<node->key<<endl;

            if( node -> left){
                q.push(node->left);
            }
            if( node -> right){
                q.push(node->right);
            }
        }

    }
    //寻找最小值的键值，利用minimum找出最小值节点，返回他的键值
    Key minimum(){
        assert(count! = 0);
        Node* minNode = minimum(root);
        return minNode->key;
    }
    //寻找最大值的键值，利用maximum找出最大值节点，返回他的键值
    Key maximum(){
        assert(count! = 0);
        Node* maxNode = maximum(root);
        return maxNode->key;
    }
    //删除最小值所在节点
    void removeMin(){
        if(root){
            root = removeMin(root);
        }
    }
    //删除最大值所在节点
    void removeMax(){
        if(root){
            root = removeMax(root);
        }
    }
private:
    //向以node为根的二叉搜索树中插入节点（key，value）
    //返回新插入节点后的二叉搜索树的根
    Node* insert(Node *node, Key key, Value value){

        if( node == NULL ){
            count ++;
            return new Node(key,value);
        }
        if( key == node->key){
            node -> value = value;
        }
        else if(key < node->key){
            node -> left = insert(node->left, key, value);
        }
        else{
            node -> right = insert(node->right, key, value);
        }

        return node;
    }

    //在以node为根的二叉搜索树中是否包含键值为key的节点
    bool contain(Node* node,Key key){

        if(node == NULL){
            return false;
        }

        if(key == Node->key){
            return true;
        }
        else if(key < Node->key){
            return contain(node->left,key);
        }
        else{
            return contain(node->right,key);
        }


    }
    //在以node为根的二叉搜索树中查找key所对应的value。
    Value* search(Node* node,Key key){
        if(node == NULL){
            return false;
        }

        if(key == Node->key){
            return &(node->value);//Value的地址
        }
        else if(key < Node->key){
            return search(node->left,key);
        }
        else{
            return search(node->right,key);
        }
    }
    //前序遍历，以N为节点，先输出节点，再遍历左右子树。
    void preOrder(Node* node){
        if( node!= NULL){
            cout<<node->key<<endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }
    //中序遍历，以N为节点，先遍历左子树，再输出节点，后遍历右子树。
    void inOrder(Node* node){
        if( node!= NULL){
            inOrder(node->left);

            cout<<node->key<<endl;
            
            inOrder(node->right);
        }
    }
    //后序遍历，以N为节点，先遍历左右子树，再输出节点。
    void postOrder(Node* node){
        if( node!= NULL){


            postOrder(node->left);
            postOrder(node->right);
            cout<<node->key<<endl;
            

        }
    }
    //释放树，利用后序遍历的思想，先释放左右子树，再释放节点。
    void destroy(Node* node){
        if(node != NULL){
            destroy (node -> left);
            destroy (node -> right);

            delete node;
            count --;
        }
    }
    //利用递归，找出第一个没有左孩子的节点，返回节点，即最小节点
    Node* minimum(Node* node){
        if(node->left == NULL){
            return node;
        }

        return minimum(node->left);
    }
    
     //利用递归，找出第一个没有右孩子的节点，返回节点，即最大节点
    Node* maximum(Node* node){
        if(node->right == NULL){
            return node;
        }

        return maximum(node->right);
    }
    //删除以node为根的二分搜索树中的最小节点，返回新的二叉搜索树的根
    Node* removeMin(Node* node){

        if(node->left == NULL){
            
            Node* rightNode = node->right;
            delete node;
            count --;
            return rightNode;
        }

        node->left = removeMin(node->left);
        return node;


    }
    //删除以node为根的二分搜索树中的最大节点，返回新的二叉搜索树的根
    Node* removeMax(Node* node){

        if(node->right == NULL){
            
            Node* leftNode = node->left;
            delete node;
            count --;
            return leftNode;
        }

        node->right = removeMin(node->right);
        return node;


    }


};

int main(){


    return 0;
}