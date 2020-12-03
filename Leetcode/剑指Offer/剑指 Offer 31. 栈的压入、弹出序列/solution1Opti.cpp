#include <stack>
#include <vector>
using namespace ::std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int>st;
    int cur=0;
    for(int i=0;i<pushed.size();++i)
    {
        st.push(pushed[i]);
        while(!st.empty()&&st.top()==popped[cur])
        { 
            st.pop();
            ++cur;
        }
    }
        return st.empty();
    }
};