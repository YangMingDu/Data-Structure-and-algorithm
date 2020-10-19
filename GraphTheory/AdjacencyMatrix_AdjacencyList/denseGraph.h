#include <iostream>
#include <vector>
#include <cassert>

using namespace ::std;

class denseGraph{

private:

    int n,m;//n个点，m条边
    bool directed;//判断有向图还是无向图
    vector<vector<bool>> g;//二维数组，两点之间是否有边

public:

    denseGraph( int n, bool directed){
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for(int i = 0; i < n; i ++){
            g.push_back(vector<bool>(n,false));
        } 
    }

    ~denseGraph(){

    }

    int V(){return n;}
    int E(){return m;}

    void addEdge( int v, int w){
        assert( v >= 0 && v < n);
        assert( w >= 0 && w < n);
        if(hasEdge(v,w)){
            return;
        }
        g[v][w] = true;
        if( !directed ){
            g[w][v] = true;
        }


        m ++;
    }
    
    bool hasEdge (int v, int w){
        assert( v >= 0 && v < n);
        assert( w >= 0 && w < n); 
        return g[v][w];      
    }


};