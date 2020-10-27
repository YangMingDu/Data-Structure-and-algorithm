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

int main(){
    int arr[] = {1,1};
    int n = sizeof(arr)/sizeof(int);

    ListNode* head = createLinkedList(arr,n);
    printLinkedList(head);

    ListNode* head2 = Solution2().partition(head,0);

    printLinkedList(head2);

    deleteLinkedList(head2);
    

}
