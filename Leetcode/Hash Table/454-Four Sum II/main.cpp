#include <iostream>
#include <vector>
#include <unordered_map>
using namespace :: std;

class Solution {
public:
    //利用哈希表结局问题，首先将A，B两个数组的任意两个元素的和的种类与出现次数放入哈希表中，再遍历所有C，D两个数组的任意两元素的和，在哈希表中寻找是否有合适的结果，以及出现的次数，计数即可。
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {

        unordered_map<int,int> record;
        int res = 0;

        for(int i = 0; i < A.size() ; i ++){
            for(int j = 0; j < B.size(); j ++){
                int sum = A[i] + B[j];
                record[sum] += 1 ;
            }
        }

        for(int k = 0; k < C.size(); k ++){
            for(int h = 0; h < D.size(); h ++){
                int sum2 = C[k] + D[h];
                int target = 0 - sum2;

                if(record.find(target) != record.end()){
                    res += record[target];
                }
            }
        }

        return res;
    }
};