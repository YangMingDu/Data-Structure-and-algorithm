#include<iostream>
using namespace :: std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
};
//创建链表
ListNode* createLinkedList(int arr[], int n){
    if( n == 0){
        return nullptr;
    }

    ListNode* head = new ListNode(arr[0]);

    ListNode* curNode = head;

    for(int i = 1; i < n; i++ ){
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }

    return head;

}
//打印链表
void printLinkedList(ListNode* head){

    ListNode*curNode = head;

    while(curNode != nullptr){
        cout << curNode->val << "->";
        curNode = curNode->next;
    }

    cout << "NULL" <<endl;

    return;

}
//删除new出的空间
void deleteLinkedList(ListNode* head){
    ListNode* curNode = head;
    while(curNode != nullptr){
        ListNode* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }
}

class Solution {
  public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* superior = dummyHead;

        for(int i = 0 ; i < m - 1; i ++){
            //指向m的前一个节点
            superior = superior->next;
        }

        ListNode* pre = nullptr;
        ListNode* cur = superior->next;

        for(int i = 0; i <= n-m; i++){

            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur; 
            cur = next;
        }
        //处理首尾节点的连接
        superior->next->next = cur;
        superior->next = pre;

        return dummyHead->next;

    }


};
class Solution2 {
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
class Solution3 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* resultathead = new ListNode(-1);
        ListNode* resultatcur = resultathead;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int l1Val = l1 ? l1->val : 0;
            int l2Val = l2 ? l2->val : 0;
            int sum = l1Val + l2Val + carry;
            carry = sum/10;
            int sumRes = sum % 10;

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
int main(){
    int arr1[] = {2,1,1};
    int arr2[] = {7,3,1};
    int n1 = sizeof(arr1)/sizeof(int);
    int n2 = sizeof(arr2)/sizeof(int);
    ListNode* head1 = createLinkedList(arr1,n1);
    ListNode* head2 = createLinkedList(arr2,n2);


    ListNode* head3 = Solution3().addTwoNumbers(head1,head2);

    printLinkedList(head3);

    deleteLinkedList(head3);
    

}
