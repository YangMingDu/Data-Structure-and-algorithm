struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    //翻转数组，尾节点变为头结点 1->2->3->4变为3->2->1->4
    ListNode* reverse(ListNode* head,ListNode* tail){
        ListNode* pre = tail;
        while(head != tail){
            ListNode* nxt = head->next;
            head->next = pre;
            pre = head;
            head = nxt;
        }
        return pre;
    }
    //分组
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        for(int i = 0;i < k;i++){
            //不足k个不用翻转
            if(cur == nullptr) return head;
            cur = cur->next;
        }
        //新的头变成翻转后的返回值
        ListNode* newhead = reverse(head,cur);
        //旧的头变成了尾，应该连接原来还没翻转的链表
        head->next = reverseKGroup(cur,k);
        return newhead;
    }
};