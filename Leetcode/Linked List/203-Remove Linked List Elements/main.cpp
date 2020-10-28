struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
class Solution {
public:
    //不使用虚拟头的方法，要考虑head的特殊性。
    ListNode* removeElements(ListNode* head, int val) {

        while(head != nullptr && head->val == val){
            ListNode* delNode = head;
            head = delNode->next;
            delete delNode;
        }
        
        if(head == nullptr){
            return head;
        }

        ListNode* cur = head;
        while(cur->next != nullptr){
            if(cur->next->val == val){
                ListNode* delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
            }

            else{
                cur = cur->next;
            }
        }

        return head;
    }
};