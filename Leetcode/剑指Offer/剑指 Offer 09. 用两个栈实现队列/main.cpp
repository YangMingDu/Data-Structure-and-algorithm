#include <stack>
using namespace ::std;
class CQueue {
    //就是题目有点难懂
public:
    stack<int> a;
    stack<int>b;
    CQueue() {



    }
    //压入栈
    void appendTail(int value) {
        a.push(value);

    }
    
    int deleteHead() {
    //当a空和b空（因为如果b不空说明之前添加了不止一个元素或者没出完，那么就先出b的顶元素就行了）的时候，返回-1
    if (b.empty() && a.empty())
            return -1;
    else if (b.empty() && !a.empty())
        {
            while (!a.empty())
            {
                //这样的话可以使先进入a栈的元素变成b栈的栈顶元素
                //其实就是用b栈来表示a栈，让FILO变成FIFO
                //B栈的顶元素就是先进入A栈的元素
                b.push(a.top());
                a.pop();
            }
        }
    //这就是输出a的栈顶元素并删除
    int temp = b.top();
    b.pop();
    return temp;     
    }
};
