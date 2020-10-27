struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    //利用数学运算将结果编写成一个新的链表
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //创建结果链表头
        ListNode* resultathead = new ListNode(-1);
        ListNode* resultatcur = resultathead;
        //进位
        int carry = 0;
        //只有l1，l2，和carry分别都是空指针和0的时候才证明运算结束
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            //如果l1或者l2部位空指针那么，他们的值就是他们节点的值。
            int l1Val = l1 ? l1->val : 0;
            int l2Val = l2 ? l2->val : 0;
            //求和
            int sum = l1Val + l2Val + carry;
            //进位
            carry = sum/10;
            //填入结果的值
            int sumRes = sum % 10;
            //创建新的结果节点，并维护结果链表的指针。
            ListNode* newNode = new ListNode(sumRes);
            resultatcur->next = newNode;
            resultatcur = newNode;

            if(l1 != nullptr){
                l1 = l1->next;
            }
            if(l2 != nullptr){
                l2 = l2->next;
            }


        }
        ListNode* ret = resultathead->next;
        delete resultathead;
        return ret;
    }
};