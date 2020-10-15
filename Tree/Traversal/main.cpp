#include <iostream>

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

};

int main(){


    return 0;
}