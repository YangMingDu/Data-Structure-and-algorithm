

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
    //反转链表，设定三个节点，pre，cur，next。
    ListNode* reverseList(ListNode* head) {
        //pre初始化为空指针
        ListNode* pre = nullptr;
        //cur指针初始化为当前指针head
        ListNode* cur = head;
        while(cur != nullptr){
            //在循环里初始化next指针，可以确保cur不是空指针，初始化head里面的next指针。
            ListNode* next = cur->next;

            cur->next = pre;

            pre = cur;
            cur = next;

        }

        return pre;

    }
};