#include <iostream>
#include <cassert>


using namespace ::std;


namespace UF5{

class UnionFind{


private:

    int* parent;
    int* rank;//rank[i] 表示的是以i为根节点的树的层数；
    int count;

public:

    UnionFind(int count){
        parent = new int[count];
        rank = new int[count];
        this -> count = count;
        for(int i = 0; i < count ; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }

    ~UnionFind(){
        delete[] parent;
        delete[] rank;
    }

    int find(int p){

        assert( p >= 0 && p < count );
        //找这个元素的父亲
        while( p != parent[p] ) {
            //路线压缩
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    bool isConnected(int p, int q){
        return find(p) == find(q);
    }

    void unionElements(int p,int q){
        int pRoot = find(p);
        int qRoot = find(q);

        if(pRoot == qRoot){
            return;
        }

        if(rank[pRoot] < rank[qRoot]){
        
            parent[pRoot] = qRoot;

        }
        else if(rank[qRoot] < rank[pRoot]){

            parent[qRoot] = pRoot;
        }
        else{//rank[qRoot] = rank[pRoot]

            parent[pRoot] = qRoot;
            rank[qRoot] += 1;

        }

    }


};

}
