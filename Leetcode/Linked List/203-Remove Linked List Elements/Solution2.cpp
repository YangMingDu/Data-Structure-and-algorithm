struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
class Solution {
public:
    //使用虚拟头，可以避免head为空或者head的值需要删除时的特殊性。
    ListNode* removeElements(ListNode* head, int val) {

        

        ListNode* dummyHead = new ListNode(-1);
        dummyHead -> next = head;

        ListNode* cur = dummyHead;
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