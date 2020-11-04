
#include<queue>
#include<iostream>
#include<vector>

using namespace :: std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class CompareListNode{
public:
    bool operator()(ListNode* node1, ListNode* node2){
        return node1->val > node2->val;
    }
};

class Solution {
public:
    //利用优先队列解决
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size() == 0)
            return NULL;

        ListNode* dummyHead = new ListNode(-1);
        ListNode* curNode = dummyHead;
        //创建优先队列他们的比较方法是元素的val值，创建最小堆
        priority_queue<ListNode*, vector<ListNode*>, CompareListNode> q;

        //将所有lists中的链表头元素都加入到优先队列中
        for(ListNode* node: lists)
            if(node != NULL)
                q.push(node);

        while(!q.empty()){
            //每次推出lists中所有头元素最小的
            ListNode* nextNode = q.top();
            q.pop();

            //将最小的插入新建的链表
            curNode->next = nextNode;
            //将最小的后面的元素加入到队列进行比较
            if(nextNode->next != NULL)
                q.push(nextNode->next);

            nextNode->next = NULL;
            curNode = curNode->next;
        }

        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};