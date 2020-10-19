#include <iostream>
#include <vector>
#include <cassert>

using namespace ::std;

class denseGraph{
//稠密图，用邻接矩阵实现
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
        //如果已经有边，直接返回
        if(hasEdge(v,w)){
            return;
        }
        g[v][w] = true;
        if( !directed ){
            g[w][v] = true;
        }


        m ++;
    }
    //判断是否已经有边
    bool hasEdge (int v, int w){
        assert( v >= 0 && v < n);
        assert( w >= 0 && w < n); 
        return g[v][w];      
    }
 class adjIterator{
    
    private:

        denseGraph &G;
        int v;
        int index;
    
    public:

        adjIterator(denseGraph &graph, int v): G(graph){

            this->v = v;
            this->index = -1;


        }

        int begin(){
            index = -1;
            return next();

        }

        int next(){
            for(index += 1 ; index < G.V() ; index ++){
                if(G.g[v][index]){
                    return index;
                }
            }
            return -1;

        }

        bool end(){

            return index >= G.V();

        }
    };

};