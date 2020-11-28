#include <iostream>
#include <vector>
using namespace ::std;
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0){
            return false;
        }
        //右上角开始，向左下看是个二叉搜索树
        int i = 0;
        int j = matrix[0].size() - 1;

        while(i < matrix.size() && j >= 0){
            if(matrix[i][j] == target){
                return true;
            }

            else if (matrix[i][j] < target){
                i ++;
            }

            else{
                j --;
            }


        }

        return false;
    }
};
