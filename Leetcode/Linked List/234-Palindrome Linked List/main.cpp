struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur != nullptr){
            ListNode* next = cur->next;

            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr ){
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        //快慢指针分割链表
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        //翻转第二段
        ListNode* L2 = slow->next;
        slow->next = nullptr;
        L2 = reverse(L2);

        ListNode* L1cur = head;
        ListNode* L2cur = L2;
        //比大小
        while(L1cur != nullptr && L2cur != nullptr){

            if(L1cur->val != L2cur->val){
                return false;
            }

            L1cur = L1cur->next;
            L2cur = L2cur->next;


        }
        return true;
    }
};