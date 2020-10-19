#include <iostream>
#include <vector>
#include <cassert>

using namespace ::std;

//稀疏图,使用邻接表
class spareGraph{


private:   

    int n,m;//n个点，m条边
    bool directed;//判断有向图还是无向图
    vector<vector<int>> g;//二维数组，具体与哪个节点相连


public:

    spareGraph(int n, bool directed){
        
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for(int i = 0; i < n; i ++){
            g.push_back(vector<int>());//每一个g[i]都放一个空vector
        } 
    }

    int V(){return n;}
    int E(){return m;}

    void addEdge( int v, int w){
        assert( v >= 0 && v < n);
        assert( w >= 0 && w < n);
        //如果已经有边，直接返回



        g[v].push_back(w);
        //防止自环边操作两次
        if( v != w && !directed ){
            g[w].push_back(v);
        }


        m ++;
    }

    bool hasEdge (int v, int w){

        assert( v >= 0 && v < n);
        assert( w >= 0 && w < n); 

        for(int i = 0 ; i < g[v].size() ; i ++){
            if( g[v][i] == w){
                return true;
            }
        }
        return false;
              
    }



};