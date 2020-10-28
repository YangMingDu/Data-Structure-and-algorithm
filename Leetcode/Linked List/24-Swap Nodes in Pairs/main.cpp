struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        //哨兵节点
        ListNode* pre = dummyHead;
        ListNode* cur = head;
        while(cur != nullptr && cur->next != nullptr  ){
            //画图即可
            pre->next = cur->next;
            cur->next = pre->next->next;
            pre->next->next = cur;

            cur = cur->next;
            pre = pre->next->next;
            
        }

        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};