#include <stack>
using namespace ::std;
class MinStack {
public:
    stack<int> A;
    stack<int> B;
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        A.push(x);
        if(B.empty()||B.top()>=x)B.push(x);
    }
    
    void pop() {
        if(A.top()==B.top())B.pop();
        A.pop();
    }
    
    int top() {
        return A.top();
    }
    
    int min() {
        return B.top();
    }
};