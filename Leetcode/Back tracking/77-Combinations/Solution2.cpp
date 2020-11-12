#include <iostream>
#include <vector>

using namespace ::std;
class Solution {

private:

        vector<vector<int>> res;
        void generateCombinations(int n, int k, int start, vector<int> &c){

            if( c.size() == k){
                res.push_back(c);
                return;
            }
            //剪枝 还有k-c.size()个空位，所以[i...n]中至少要有k-c.size()个元素。
            //i最多为n-（k-c.size()）+1再往后就没有足够的位数进行组合了
            //例如1234 2 中的4
            for(int i = start ; i <= n -(k - c.size()) + 1 ; i++){
                c.push_back(i);
                generateCombinations(n,k,i+1,c);

                c.pop_back();
            }

        }

public:
    vector<vector<int>> combine(int n, int k) {
        
        res.clear();
        if(n == 0 || k <= 0 || k > n){
            return res;
        }

        vector<int> c;
        generateCombinations(n,k,1,c);
        return res;





    }
};