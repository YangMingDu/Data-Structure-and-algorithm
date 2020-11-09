#include <vector>
#include <string>
#include <cassert>
using namespace ::std;
class Solution {
private:
    vector<string> res;
    //[0...9]数字对应的字母
    const string Map[10] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void trouverLesCombinaison(const string digits,const string &s,int index){
        if(index == digits.size()){
            //每当index遍历到最后一个的时候就是一种结果
            res.push_back(s);
            return;
        }

        char c = digits[index];
        assert(c != 1 && c <= '9' && c >= '0');

        string letters = Map[c - '0'];
        for(int i = 0 ; i < letters.size(); i++){
            trouverLesCombinaison(digits,s+letters[i],index+1); 
        }

        return;




    }


public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return res;
        }
        trouverLesCombinaison(digits,"",0);
        return res;

    }
};