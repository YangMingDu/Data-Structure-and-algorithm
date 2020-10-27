
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
 
class Solution {
  public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* superior = dummyHead;

        for(int i = 0 ; i < m - 1; i ++){
            //指向m的前一个节点
            superior = superior->next;
        }

        ListNode* pre = nullptr;
        ListNode* cur = superior->next;

        for(int i = 0; i <= n-m; i++){

            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur; 
            cur = next;
        }
        //处理首尾节点的连接
        superior->next->next = cur;
        superior->next = pre;

        return dummyHead->next;

    }


};
