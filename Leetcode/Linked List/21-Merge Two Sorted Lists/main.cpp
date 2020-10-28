struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    //和归并排序的归并操作一样
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //答案链表
        ListNode* dummyhead = new ListNode(-1);
        ListNode* cur = dummyhead;

        while(l1 != nullptr && l2 != nullptr){
            //判断大小，答案链表连接小的，并维护
            if(l1->val > l2->val){
                cur->next = l2;
                l2 = l2->next;
            }
            else{
                cur->next = l1;
                l1 = l1->next;
            }

            //维护答案链表

            cur = cur->next;
        }

        //如果一个链表已经遍历完了，那么直接把答案链表头接入另一个链表就行了
        if(l1 == nullptr){
            cur->next = l2;
        }
        else if(l2 == nullptr){
            cur->next = l1;
        }

        ListNode* ret = dummyhead->next;

        delete dummyhead;



        return ret;

        
    }
};