#include <vector>
using namespace ::std;
class Solution {
public:
    //滑动窗口
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        if(target < 3){
            return res;
        }
        //正整数从1开始
        int l = 1;
        int r = l+1;
        
        while( r <= target && l < r){
            int sum = 0;
            for(int i = l ; i <= r; i++){
                sum += i;
            }

            if(sum == target){
                vector<int> temp;
                for(int i = l ; i <= r; i++){
                    temp.push_back(i);
                }
                res.push_back(temp);
                l++;                

            }

            else if(sum < target){
                r++;
            }

            else{
                l++;
            }
        }


        return res;
    }
};