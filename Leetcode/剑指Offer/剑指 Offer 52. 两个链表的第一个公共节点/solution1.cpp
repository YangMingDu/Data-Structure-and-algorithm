struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    //浪漫相遇法
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *node1 = headA;
        ListNode *node2 = headB;
        //设交集链表长c,链表1除交集的长度为a，链表2除交集的长度为b，有
        //a + c + b = b + c + a
        //若无交集，则a + b = b + a
        //会达成node1 == node2 == NULL
        while (node1 != node2) {
            
            node1 = node1 != nullptr ? node1->next : headB;
            node2 = node2 != nullptr ? node2->next : headA;
        }
        return node1;
    }
};
