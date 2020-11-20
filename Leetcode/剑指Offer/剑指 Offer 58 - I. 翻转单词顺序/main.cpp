#include <string>
#include <stack>
using namespace ::std;
class Solution {
public:
    string reverseWords(string s) {
        //以单词的模式建栈
        stack<string> stk;
        string str;
        string ret;
        if(s.size() == 0){
            return ret;
        }
        for(auto &i:s){
            if(i != ' '){
                str += i;
            }
            else if(str.size() != 0){
                stk.push(str);
                str.clear();
            }
        }
        //万一最后没有空格，上一个循环就会剩下一个str没有推入栈
        //此时推入最后一个str
        if(str.size() && str != " "){
            stk.push(str);
        }
        //先进后出
        while(!stk.empty()){
            ret += stk.top();
            ret += " ";
            stk.pop();
        }
        //把最后一个空格删除
        if(ret.size() != 0){
            ret.pop_back();
        }
        return ret;
    }
};