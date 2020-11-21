#include <stack>
#include <vector>
using namespace ::std;
class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> res;
    stack<int> record;
    MinStack() {
        
    }
    
    void push(int x) {
        record.push(x);
        res.push_back(x);
    }
    
    void pop() {
        record.pop();
        res.pop_back();
    }
    
    int top() {
        return record.top();
    }
    
    int min() {
        int mins = INT_MAX;
        for(int i = 0 ; i < res.size(); i++){
            mins = ::min(mins,res[i]);
        }
        return mins;
    }
};