  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1 = new ListNode(-1); // 记录比x小的节点组成的链表
        ListNode* head2 = new ListNode(-1); // 记录比x大的节点组成的链表
        ListNode* cur1 = head1;
        ListNode* cur2 = head2;
        while (head) {
            if (head -> val < x) {
                cur1 -> next = head;
                cur1 = cur1 -> next;
            } else {
                cur2 -> next = head;
                cur2 = cur2 -> next;
            }
            head = head -> next;
        }
        // 将两个链表拼接起来
        cur2 -> next = nullptr;
        cur1 -> next = head2 -> next;

        ListNode *ret = head1 -> next;
        delete head1;
        delete head2;
        return ret;
    }
};