#include <vector>
#include <iostream>

using namespace :: std;
class Solution {
public:
    //DP
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0){
            return 0;
        }
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> res = grid;
        //初始化第一行因为，第一行的前一个元素只能是他左边的
        for(int j = 1 ; j < m ; j ++)
            res[0][j] += res[0][j-1];
        //初始化第一列因为，第一列的前一个元素只能是他上边的
        for(int i = 1 ; i < n ; i ++)
            res[i][0] += res[i-1][0];

        for(int i = 1 ; i < n ; i ++)
            for(int j = 1 ; j < m ; j ++)
                //等于他自己的值再加上到达他的两个点的最小值。
                res[i][j] += min(res[i-1][j], res[i][j-1]);

        return res[n-1][m-1];
    }
    
};