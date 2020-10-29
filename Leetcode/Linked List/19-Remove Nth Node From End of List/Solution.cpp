struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    //双指针法：利用倒数第n个的前一个元素到null的距离不变，设置两个指针。
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode* p = dummyHead;
        ListNode* q = dummyHead;
        //q先前进到合适的距离
        for(int i = 0 ; i < n + 1; i++ ){
            q = q->next;
        }

        //当q没有指向最后的null之前，pq一起前进
        while(q != nullptr){
            p = p->next;
            q = q->next;
        }
        //找到删除元素的前一个元素，进行删除
        ListNode* delNode = p->next;
        p->next = delNode->next;
        delete delNode;

        ListNode* ret = dummyHead->next;
        delete dummyHead;

        return ret;
      
    }
};