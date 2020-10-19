#include <iostream>
#include <ctime>
#include "sparseGraph.h"


using namespace :: std;
int main(){
    
    
    int N = 20;
    int M = 100;

    srand( time(NULL) );
    //生成20个点100条边的图
    spareGraph g1(N,false);
    for (int i = 0 ; i < M ; i ++){
        int a = rand()%N;
        int b = rand()%N;
        //连接边
        g1.addEdge( a , b);

    }
    for( int v = 0 ; v < N; v ++){
        cout << v << " ";
        spareGraph::adjIterator adj( g1 , v);
        for( int w  = adj.begin() ; !adj.end() ; w = adj.next() ){
            cout<<w<<" ";
        }
        cout<<endl;
    }

}