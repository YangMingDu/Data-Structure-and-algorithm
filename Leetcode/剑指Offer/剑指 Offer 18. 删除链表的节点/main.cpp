#include <iostream>
using namespace ::std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head == nullptr){
            return head;
        }
        if(head->val == val){
            return head->next;
        }
        ListNode* pre = nullptr;
        ListNode* cur = head;

        while(cur != nullptr ){
            ListNode* next = cur->next;
            if(cur->val != val){
                pre = cur;
                cur = next; 
                 
            }
            else{
                cur->next = nullptr;
                pre->next = next;
                break; 
            }
        }

        return head;
    }
};