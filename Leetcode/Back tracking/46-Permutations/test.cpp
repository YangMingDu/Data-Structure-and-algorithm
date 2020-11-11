#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/// Most Naive Recursive
/// Time Complexity: O(n^n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> res;
    //检查是否重复
    vector<bool> used;

    void backTravel(int index,vector<int>& nums,vector<int> &p){

        if(index == nums.size()){
            res.push_back(p);
            return;
        }

        for(int i = 0 ; i < nums.size() ; i++){
            if(!used[i]){
                p.push_back(nums[i]);
                used[i] = true;
                backTravel(index + 1,nums,p);
                //回溯步骤，维护used，并且踢掉之前的元素
                used[i] = false;
                p.pop_back();

            }
        }

    }







    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> p;
        res.clear();
        if(nums.size() == 0){
            return res;
        }
        used = vector<bool>(nums.size(),false);
        backTravel(0,nums,p);
        return res;


    }
};

void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> nums1 = {1,1,2};
    vector<vector<int>> res1 = Solution().permute(nums1);
    for(const vector<int>& tres: res1)
        printVec(tres);


    return 0;
}