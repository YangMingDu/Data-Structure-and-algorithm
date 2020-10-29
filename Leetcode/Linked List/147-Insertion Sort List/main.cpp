struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution 
{
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }


        //建立新的链表进行操作和对比。
        ListNode* testHead = new ListNode(-1);
        testHead->next = head;



        ListNode* pre = head;
        ListNode* cur = pre->next;

        while(cur != nullptr){

            //因为前面已经有序，所以当cur值大于pre值说明还是有序，不需要排序。
            if(cur->val >= pre->val){
                pre = cur;
                cur = cur->next;
            }
            //需要排序
            else{

                //拿出要插入的节点
                pre->next = cur->next;
                cur->next = nullptr;




                ListNode* curTest = testHead;
                //找到合适的位置
                while(curTest->next->val <= cur->val){
                    curTest = curTest->next;
                } 

                //维护
                cur->next = curTest->next;
                curTest->next = cur;
                cur = pre->next;


            }
            

            
        }

        ListNode* ret = testHead->next;
        delete testHead;
        return ret;
        
        
        
        
        
        
        
        
        }
};