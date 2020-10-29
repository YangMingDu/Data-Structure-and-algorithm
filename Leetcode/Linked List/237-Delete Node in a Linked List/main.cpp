
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
class Solution {
public:
    //实质上是删除了node后面的节点，将node后面的节点的值放到node节点上，再删除后面的就行了。
    void deleteNode(ListNode* node) {
        if(node == nullptr){
            return ;
        }
        //赋值
        node->val = node->next->val;
        //锁定删除节点
        ListNode* delNode = node->next;
        node->next = node->next->next;

        delete delNode;
    }
};