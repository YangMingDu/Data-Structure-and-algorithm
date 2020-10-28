
 
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    //与82的不同就是设置一个循环，记录重复的值，在83删除重复值之后再维护cur就行了。
    ListNode* deleteDuplicates(ListNode* head) {
        //首先判断链表为空和只有一个节点的情况
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        //创建虚拟链表
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* cur = head;
        //由于用到next的next节点，所以也要判断next节点是否存在
        while(cur != nullptr && cur->next != nullptr){
            ListNode* next = cur->next;
            //如果出现重复
            if(cur->val == next->val){
                //记录重复节点的值
                int val = cur -> val;
                while(cur->next != nullptr && cur->next->val == val  ){
                    ListNode* delNode = cur->next;
                    cur->next = delNode->next;
                    delete delNode;
                }
                //维护pre和cur
                pre->next = cur->next;
                //删除最后一个重复的节点
                ListNode* delNode = cur;
                cur = cur->next; 
                delete delNode;
            }
            //无重复
            else{
                pre = cur;
                cur = next;
            }

        }

        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};