#include<stack>
#include<string>
#include<iostream>
#include<vector>

using namespace :: std;
class Solution {
public:
    string simplifyPath(string path) {
        path+='/';
        stack<string> temp_stack;
        string temp_string;
        for(auto c:path){
            //两个'/'之间为单级目录子串
            if(c=='/'){
                //地址从前向后跳转，如两个'/'之间的地址字符串是“..”，切换上一级目录，即将最后压入的一级目录弹出
                if(temp_string==".."){
                    if(!temp_stack.empty()) temp_stack.pop();
                    //考虑特殊情况，如果前面没有进入子目录，一开始就是".."，此时既不能压入栈也无法弹出，需要排除，不做操作即可
                }
                //其他情况，如两个'/'之间的地址字符串存在，且不为'.'（同级目录，无变化），必为字母组成的地址，因此压入栈
                else if (temp_string!="." && !temp_string.empty()){
                    temp_stack.push(temp_string);
                }
                //清空单级目录字符串，准备记录下两个'/'之间的目录字符串
                temp_string.clear();
            }
            //记录单级目录字符串
            else{
                temp_string.push_back(c);
            }
        }
        //从栈中取出各级目录子串，加上'/'形成完整地址
        string result;
        while(!temp_stack.empty()){
            result='/'+temp_stack.top()+result;
            temp_stack.pop();
        }
        //特殊情况，栈中无元素，没有扫描到有效地址，则返回'/'
        if(result.empty()) result="/";
        return result;
    }
};