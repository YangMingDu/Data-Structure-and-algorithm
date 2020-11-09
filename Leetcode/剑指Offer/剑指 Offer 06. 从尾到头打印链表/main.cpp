#include <iostream>
#include <vector>

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
//反转链表
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur != nullptr){
            ListNode* next = cur->next;
            
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        while(pre){
            res.push_back(pre->val);
            pre = pre->next;
        }

        return res;

    }
};