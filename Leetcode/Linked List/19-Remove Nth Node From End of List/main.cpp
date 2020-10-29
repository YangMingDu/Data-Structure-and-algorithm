struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    //暴力解法：先遍历链表查看有多少个节点，之后再遍历到要删除的前一个节点，进行删除操作即可。
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == nullptr){
            return head;
        }
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* cur2 = dummyHead; 

        ListNode* cur = head;



        int count = 0;
        while(cur != nullptr){
            
            ++count;
            cur = cur->next;
        }

        for(int i = 0; i < count - n; i++){
            cur2 = cur2->next;
        }


        ListNode* delNode = cur2->next;
        cur2->next = delNode->next;
        delete delNode;  

        ListNode* ret = dummyHead->next;
        delete dummyHead; 
        
        return ret;
      
    }
};