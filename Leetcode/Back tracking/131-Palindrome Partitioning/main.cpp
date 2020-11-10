#include <vector>
#include <string>


using namespace ::std;
class Solution {
public:
    vector<vector<string>> res;
    vector<string> temp;
    
    //判断是否为回文串
    bool isPalindrome(string a){
        if(a.size() == 0){
            return false;
        }
        if(a.size() == 1){
            return true;
        }

        int l = 0;
        int r = a.size()-1;

        while(l<r){
            if(a[l] == a[r]){
                l ++;
                r --;
            }
            else{
                return false;
            }
        }

        return true;

    }
    //回溯法
    void backtravel(const string &s, const int &left, const int &right) {
        //到字符串末尾了，将本次结果记录下来
        if (left > right) {
            res.push_back(temp);
            return;
        }
        //从index为a开始截取长度为1,2,3..的子串进行验证，成功则用剩下的部分递归
        for (int i = 1; i <= right - left + 1; i++) {
            if (isPalindrome(s.substr(left, i))) {
                temp.push_back(s.substr(left, i));
                // 以上一次成功的位置为起点再次进行递归
                backtravel(s, left+i, right);
                temp.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {

    backtravel(s, 0, s.size()-1);
    return res;


    }
};
