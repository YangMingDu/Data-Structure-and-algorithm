#include<iostream>
#include<unordered_set>
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
    //set存储节点法
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        unordered_set<ListNode*> record;
        if(headA == nullptr || headB == nullptr){
            return nullptr;
        }

        while(headA != nullptr){
            record.insert(headA);
            headA = headA->next;
        }

        while(headB != nullptr){
            if(record.find(headB) != record.end()){
                return headB;
                break;
            }
            headB = headB->next;
        }

        return nullptr;

    }
};
