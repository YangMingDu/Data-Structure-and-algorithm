#include <vector>
using namespace ::std;
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        if(n == 0){
            return res;
        }
        int digit = 1;
        for(int i = 0 ; i < n; i++){
            digit *= 10;
        }
        
        for(int i = 1 ; i < digit; i++){
            res.push_back(i);
        }

        return res;
    }
};