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
        Node(Node* node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
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
    //删除键值为key的节点
    void remove(Key key){
        root = remove(root,key);
    }
    
    // 寻找key的floor值, 递归算法
    // 如果不存在key的floor值(key比BST中的最小值还小), 返回NULL
    Key* floor(Key key){

        if( count == 0 || key < minimum() )
            return NULL;

        Node *floorNode = floor(root, key);
        return &(floorNode->key);
    }

    // 寻找key的ceil值, 递归算法
    // 如果不存在key的ceil值(key比BST中的最大值还大), 返回NULL
    Key* ceil(Key key){

        if( count == 0 || key > maximum() )
            return NULL;

        Node *ceilNode = ceil(root, key);
        return &(ceilNode->key);
    }

    // 查找key的前驱
    // 如果不存在key的前驱(key不存在, 或者key是整棵二叉树中的最小值), 则返回NULL
    Key* predecessor(Key key){

        Node *node = search(root, key);
        // 如果key所在的节点不存在, 则key没有前驱, 返回NULL
        if(node == NULL)
            return NULL;

        // 如果key所在的节点左子树不为空,则其左子树的最大值为key的前驱
        if(node->left != NULL)
            return &(maximum(node->left)->key);

        // 否则, key的前驱在从根节点到key的路径上, 在这个路径上寻找到比key小的最大值, 即为key的前驱
        Node* preNode = predecessorFromAncestor(root, key);
        return preNode == NULL ? NULL : &(preNode->key);
    }

    // 查找key的后继, 递归算法
    // 如果不存在key的后继(key不存在, 或者key是整棵二叉树中的最大值), 则返回NULL
    Key* successor(Key key){

        Node *node = search(root, key);
        // 如果key所在的节点不存在, 则key没有前驱, 返回NULL
        if(node == NULL)
            return NULL;

        // 如果key所在的节点右子树不为空,则其右子树的最小值为key的后继
        if(node->right != NULL)
            return &(minimum(node->right)->key);

        // 否则, key的后继在从根节点到key的路径上, 在这个路径上寻找到比key大的最小值, 即为key的后继
        Node* sucNode = successorFromAncestor(root, key);
        return sucNode == NULL ? NULL : &(sucNode->key);
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
    //删除以node为根的二分搜索树中的键值为key的节点，返回新的二叉搜索树的根
    Node* remove(Node* node,Key key){

        if( node == NULL){
            return NULL;
        }

        if(key < node->key){
            node->left  = remove( node -> left, key);
            return node;
        }
        else if(key > node->key){
            node->right  = remove( node -> right, key);
            return node;
        }
        else{
            if(node -> left == NULL){
                Node* rightNode = node->right;
                delete node;
                count--;
                return rightNode;
            }
            else if(node -> right == NULL){
                Node* leftNode = node->left;
                delete node;
                count--;
                return leftNode;
            }
            Node *delNode = node;//原来的节点，也就是要删除的节点
            Node *successor = new Node(minimum(node->right));//后继的节点
            count ++;

            successor->right = removeMin(node -> right);
            successor->left = node->left;

            delete delNode;
            count--;
            return successor;
        }
    }
         // 在以node为根的二叉搜索树中, 寻找key的floor值所处的节点, 递归算法
    Node* floor(Node* node, Key key){

        if( node == NULL )
            return NULL;

        // 如果node的key值和要寻找的key值相等
        // 则node本身就是key的floor节点
        if( node->key == key )
            return node;

        // 如果node的key值比要寻找的key值大
        // 则要寻找的key的floor节点一定在node的左子树中
        if( node->key > key )
            return floor( node->left , key );

        // 如果node->key < key
        // 则node有可能是key的floor节点, 也有可能不是(存在比node->key大但是小于key的其余节点)
        // 需要尝试向node的右子树寻找一下
        Node* tempNode = floor( node->right , key );
        if( tempNode != NULL )
            return tempNode;

        return node;
    }


    // 在以node为根的二叉搜索树中, 寻找key的ceil值所处的节点, 递归算法
    Node* ceil(Node* node, Key key){

        if( node == NULL )
            return NULL;

        // 如果node的key值和要寻找的key值相等
        // 则node本身就是key的ceil节点
        if( node->key == key )
            return node;

        // 如果node的key值比要寻找的key值小
        // 则要寻找的key的ceil节点一定在node的右子树中
        if( node->key < key )
            return ceil( node->right , key );

        // 如果node->key > key
        // 则node有可能是key的ceil节点, 也有可能不是(存在比node->key小但是大于key的其余节点)
        // 需要尝试向node的左子树寻找一下
        Node* tempNode = ceil( node->left , key );
        if( tempNode != NULL )
            return tempNode;

        return node;
    }


    // 在以node为根的二叉搜索树中, 寻找key的祖先中,比key小的最大值所在节点, 递归算法
    // 算法调用前已保证key存在在以node为根的二叉树中
    Node* predecessorFromAncestor(Node* node, Key key){

        if(node->key == key)
            return NULL;

        if(key < node->key)
            // 如果当前节点大于key, 则当前节点不可能是比key小的最大值
            // 向下搜索到的结果直接返回
            return predecessorFromAncestor(node->left, key);
        else{
            assert(key > node->key);
            // 如果当前节点小于key, 则当前节点有可能是比key小的最大值
            // 向右继续搜索, 将结果存储到tempNode中
            Node* tempNode = predecessorFromAncestor(node->right, key);
            if(tempNode)
                return tempNode;
            else
                // 如果tempNode为空, 则当前节点即为结果
                return node;
        }
    }

    // 在以node为根的二叉搜索树中, 寻找key的祖先中,比key大的最小值所在节点, 递归算法
    // 算法调用前已保证key存在在以node为根的二叉树中
    Node* successorFromAncestor(Node* node, Key key){

        if(node->key == key)
            return NULL;

        if(key > node->key)
            // 如果当前节点小于key, 则当前节点不可能是比key大的最小值
            // 向下搜索到的结果直接返回
            return successorFromAncestor(node->right, key);
        else{
            assert(key < node->key);
            // 如果当前节点大于key, 则当前节点有可能是比key大的最小值
            // 向左继续搜索, 将结果存储到tempNode中
            Node* tempNode = predecessorFromAncestor(node->left, key);
            if(tempNode)
                return tempNode;
            else
                // 如果tempNode为空, 则当前节点即为结果
                return node;
        }
    }



};

int main(){


    return 0;
}