#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    //一个一个merge
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size() == 0)
            return NULL;

        ListNode* ret = NULL;
        for(ListNode* list: lists)
            //将上一个merge的结果和下一个链表继续merge，直至全部融为一个链表。
            ret = merge(ret, list);
        return ret;
    }

private:
    ListNode* merge(ListNode* list1, ListNode* list2){

        ListNode* dummyHead = new ListNode(-1);
        ListNode* curNode = dummyHead;
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                curNode->next = list1;
                list1 = list1->next;
            }
            else{
                curNode->next = list2;
                list2 = list2->next;
            }

            curNode = curNode->next;
            curNode->next = NULL;
        }
        //如果触发了上一步的终止条件，也就是L1或L2有一个为空了（全部merge了），那么直接将另一个剩下的连上链表
        if(list1)
            curNode->next = list1;
        if(list2)
            curNode->next = list2;

        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};

