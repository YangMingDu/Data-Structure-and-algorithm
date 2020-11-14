#include <vector>
#include <string>
using namespace ::std;
class Solution {
public:
    //四个方向移动
    int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    //二维数组行列
    int m,n;
    vector<vector<bool>> isVisited;
    bool inArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y <n;
    }

    bool searchWord(vector<vector<char>> &board, string& word,int index,int startx,int starty){
        if(index == word.size() - 1){
            return board[startx][starty] == word[index];
        }

        if(board[startx][starty] == word[index]){
            isVisited[startx][starty] = true;
            //从startx和starty出发，向四个方向寻找
            for( int i  = 0 ; i < 4 ; i ++){
                int newx = startx + d[i][0];
                int newy = starty + d[i][1];
                if( inArea(newx,newy) && !isVisited[newx][newy]){
                    if(searchWord(board,word,index+1,newx,newy)){
                        return true;
                    }
                }
            }
            //回溯
            isVisited[startx][starty] = false;
        }

        return false;



    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        isVisited = vector<vector<bool>>(m,vector<bool>(n,false));

        for( int i = 0 ; i < board.size();i++){
            for(int j = 0 ; j < board[i].size(); j++){
                if(searchWord(board,word,0,i,j)){
                    return true;
                }
            }
        }

        return false;

    }
};