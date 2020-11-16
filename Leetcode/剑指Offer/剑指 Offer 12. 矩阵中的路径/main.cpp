#include <vector>
#include <string>
using namespace ::std;
class Solution {
public:

    int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    vector<vector<bool>> isVisited;
    int m,n;

    bool inArea(int x, int y){
        return x < m && y < n && x >=0 && y >= 0;
    }

    bool searchWord(vector<vector<char>>& board,string& word,int startx,int starty,int index){

        if(index == word.size() - 1){
            return board[startx][starty] == word[index];
        }
        //如果在此位置发现了有效字母
        if(board[startx][starty] == word[index]){
            //先标记
            isVisited[startx][starty] = true;
            //向四个方面寻找下一个是否存在有效字母
            for(int i = 0 ; i < 4; i++ ){
                int newx = startx + d[i][0];
                int newy = starty + d[i][1];
                if(inArea(newx,newy) && !isVisited[newx][newy] && searchWord(board,word,newx,newy,index +1)){
                    return true;

                }
            
            }
            //回溯
            isVisited[startx][starty] = false;
        }

        return false;



    }
    //和第七十九题一样，用回溯法
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();

        n = board[0].size();
        isVisited = vector(m,vector<bool>(n, false));


        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0 ; j < board[i].size(); j++){
                //从不同地方开始搜索
                if(searchWord(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;

    }
};