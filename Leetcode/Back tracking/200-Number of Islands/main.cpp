#include <vector>
#include <string>
using namespace ::std;
class Solution {
public:
    int m;
    int n;
    int res;
    vector<vector<bool>> isVisited;
    int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    bool inArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y <n;
    }

    void dfs(vector<vector<char>>& grid , int x, int y){
        isVisited[x][y] = true;
        for( int i  = 0 ; i < 4 ; i ++){
                int newx = x + d[i][0];
                int newy = y + d[i][1];
                if( inArea(newx, newy) && !isVisited[newx][newy] && grid[newx][newy] == '1'){
                    dfs(grid,newx,newy);
                }
        }

        return;
    }


    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        if( m == 0){
            return 0 ;
        }
        n = grid[0].size();
        res = 0;
        isVisited = vector<vector<bool>>(m,vector<bool>(n,false));

        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0 ;j < grid[i].size(); j++){
                if(grid[i][j] == '1' && !isVisited[i][j]){
                    res ++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;

    }
};