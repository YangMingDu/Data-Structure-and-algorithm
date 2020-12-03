#include <stack>
#include <vector>
using namespace ::std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size() ){
            return false;
        }

        if(pushed.size() == 0){
            return true;
        }

        stack<int> record;
        int pointerPush = 1;
        int pointerPop = 0;
        record.push(pushed[0]);
        

        while(pointerPush < pushed.size()){
            if(record.size() == 0){
                record.push(pushed[pointerPush]);
                pointerPush ++ ;
            }

            int i = record.top();

            if( i != popped[pointerPop]){
                record.push(pushed[pointerPush]);
                pointerPush ++ ;
            }

            else{
                record.pop();
                pointerPop ++ ;
            }
           

        }

        while(record.size()!= 0 && record.top() == popped[pointerPop]){
            record.pop();
            pointerPop++;
        }
        //判断栈中是否还有元素，如果有说明pop受到阻碍
        //也说明不符合要求
        if(record.size() != 0){
            return false;
        }
        else{
            return true;
        }


    }
};