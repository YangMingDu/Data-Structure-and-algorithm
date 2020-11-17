struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int count = 0;
        ListNode* cur = head;
        while(cur != nullptr){
            cur = cur->next;
            count ++;
        }

        ListNode* res = head;
        for(int i = 0 ; i < count - k; i ++){
            res = res->next;
        }

        return res;
    }
};