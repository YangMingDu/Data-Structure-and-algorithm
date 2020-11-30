#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> res;
    vector<bool> used;
    void backTravel(int index,string s,string p){
        if(index == s.size()){
            res.push_back(p);
            return;
        }

        for(int i = 0 ; i < s.size(); i++){
            if(!used[i]){
                //这是排序的原因
                if(i > 0 && s[i] == s[i-1] && !used[i-1]){
                    continue;
                }
                p.push_back(s[i]);
                used[i] = true;
                backTravel(index + 1,s,p);
                used[i] = false;
                p.pop_back();
            }
        }
    }
    
    
    
    vector<string> permutation(string s) {
        string p;
        res.clear();
        if(s.size() == 0){
            return res;
        }
        used = vector<bool>(s.size(),false);
        //一定要排序
        sort(s.begin(),s.end());
        backTravel(0,s,p);
        return res;

    }
};