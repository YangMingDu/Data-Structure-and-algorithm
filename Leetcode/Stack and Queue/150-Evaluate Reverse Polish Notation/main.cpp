#include<stack>
#include<string>
#include<iostream>
#include<vector>

using namespace :: std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            //当遍历到运算符号
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                //记录并弹出运算符号前面的两个数字
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                //计算并将结果压入栈中
                if (tokens[i] == "+") st.push(num2 + num1);
                if (tokens[i] == "-") st.push(num2 - num1);
                if (tokens[i] == "*") st.push(num2 * num1);
                if (tokens[i] == "/") st.push(num2 / num1);
            } 
            //数字直接压入栈中
            else {
                st.push(stoi(tokens[i]));
            }
        }
        //结果为栈顶元素
        int result = st.top();
        st.pop();
        return result;
    }
};