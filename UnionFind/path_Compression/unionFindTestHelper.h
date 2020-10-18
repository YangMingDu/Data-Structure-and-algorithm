#include <iostream>
#include <ctime>
#include "unionFind1.h"
#include "unionFind2.h"
#include "unionFind3.h"
#include "unionFind4.h"
#include "unionFind5.h"
using namespace :: std;

namespace unionFindTestHelper{

    void testUF1(int n){
        srand( time(NULL) );
        UF1 :: UnionFind uf = UF1 ::UnionFind(n);

        time_t startTime = clock();

        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        time_t endTime = clock();
        cout << "UF1, "<<2*n<<" ops, "<<double(endTime - startTime)/CLOCKS_PER_SEC<<endl;
    }

    void testUF2(int n){
        srand( time(NULL) );
        UF2 :: UnionFind uf = UF2 ::UnionFind(n);

        time_t startTime = clock();

        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        time_t endTime = clock();
        cout << "UF2, "<<2*n<<" ops, "<<double(endTime - startTime)/CLOCKS_PER_SEC<<endl;
    }
    
        void testUF3(int n){
        srand( time(NULL) );
        UF3 :: UnionFind uf = UF3 ::UnionFind(n);

        time_t startTime = clock();

        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        time_t endTime = clock();
        cout << "UF3, "<<2*n<<" ops, "<<double(endTime - startTime)/CLOCKS_PER_SEC<<endl;
    }
    void testUF4(int n){
        srand( time(NULL) );
        UF4 :: UnionFind uf = UF4 ::UnionFind(n);

        time_t startTime = clock();

        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        time_t endTime = clock();
        cout << "UF4, "<<2*n<<" ops, "<<double(endTime - startTime)/CLOCKS_PER_SEC<<endl;
    }
    void testUF5(int n){
        srand( time(NULL) );
        UF5 :: UnionFind uf = UF5 ::UnionFind(n);

        time_t startTime = clock();

        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        time_t endTime = clock();
        cout << "UF5, "<<2*n<<" ops, "<<double(endTime - startTime)/CLOCKS_PER_SEC<<endl;
    }
}