
 
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //首先判断链表为空和只有一个节点的情况
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        //创建虚拟链表
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* cur = head;
        //由于用到next的next节点，所以也要判断next节点是否存在
        while(cur != nullptr && cur->next != nullptr){
            ListNode* next = cur->next;
            //如果出现重复
            if(cur->val == next->val){
                //将cur指向next的下一个节点
                cur->next = next->next;
                //将重复节点指向空
                next->next = nullptr;
            }
            //无重复
            else{
                cur = next;
            }

        }

        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};