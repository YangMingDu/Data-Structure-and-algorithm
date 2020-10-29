struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0){
            return head;
        }

        ListNode* cur = head;
        
        ListNode* curhead = head;

        int count = 1;

        while(cur->next != nullptr){
            count ++;
            cur = cur->next;
        }
        //形成环形链表
        cur->next = head;
        
        int move = count - k;

        //如果k大于链表长度
        if(move <= 0){
            move = count - k % count;
        }


        //找到应该切断环形链表的前一个节点
        for(int i = 0; i < move - 1; i++){
            curhead=curhead->next;
        }

        //断开环形链表
        ListNode* ret = curhead->next;
        curhead->next = nullptr;



        return ret;
        


    }
};