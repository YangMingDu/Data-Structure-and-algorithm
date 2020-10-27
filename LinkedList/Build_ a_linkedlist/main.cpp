#include<iostream>
using namespace :: std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
};
 
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

void printLinkedList(ListNode* head){

    ListNode*curNode = head;

    while(curNode != nullptr){
        cout << curNode->val << "->";
        curNode = curNode->next;
    }

    cout << "NULL" <<endl;

    return;

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

int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(int);

    ListNode* head = createLinkedList(arr,n);
    printLinkedList(head);

    ListNode* head2 = Solution().reverseBetween(head,2,4);

    printLinkedList(head2);
    

}
