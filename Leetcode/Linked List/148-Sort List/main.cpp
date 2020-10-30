struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    //链表中的归并排序
    ListNode * sortList(ListNode * head)
    {
        return  (head == nullptr)? nullptr: mergeSort(head);
    }

private:
    ListNode * findMid(ListNode * head)
    {
        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * previous = nullptr;
        while (fast != nullptr && fast->next != nullptr)
        {
            previous = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // split the list into two parts
        previous->next = nullptr;
        return slow;
    }

    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2)
    {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }else{
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
    }

    ListNode * mergeSort(ListNode * head)
    {
        if (head->next == nullptr) return head;
        ListNode * mid = findMid(head);
        ListNode * l1 = mergeSort(head);
        ListNode * l2 = mergeSort(mid);
        return mergeTwoLists(l1, l2);
    }

};

