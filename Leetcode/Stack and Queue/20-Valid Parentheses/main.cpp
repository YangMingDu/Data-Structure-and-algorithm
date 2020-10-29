#include<stack>
#include<string>
#include<iostream>

using namespace :: std;

class Solution {
public:
    bool isValid(string s) {

        stack<char> stack;
        //将左括号压入栈
        for(int i = 0 ; i < s.size() ; i ++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stack.push(s[i]);
            }
            //出现右括号时
            else{
                //栈中没有元素，说明没有与之对应的左括号
                if(stack.size() == 0){
                    return false;
                }
                //记录栈顶元素并弹出
                char c = stack.top();
                stack.pop();

                char match;
                //查看是否匹配
                if(s[i] == ')'){
                    match = '(';
                }
                else if(s[i] == ']'){
                    match = '[';
                }
                else{
                    match = '{';
                }

                if(c != match){
                    return false;
                }


            }
        }
        //如果栈内还有元素，说明有左括号没有与之对应的右括号。
        if(stack.size() != 0){
            return false;
        }

        return true;

    }
};