#include <iostream>
#include <queue>
#include <ctime>

using namespace std;

int main(){
    srand( time(NULL) );

    //默认情况下为最大堆
    priority_queue<int> pq;


    for(int i = 0 ; i < 10; i++ ){
        int num = rand()%100;
        pq.push(num);
        cout << "insert "<<num<<" in priority queue"<<endl;

    }
    while(!pq.empty()){
        cout<< pq.top() <<" ";
        pq.pop();
    }
    cout<< endl;

    //这种情况为最小堆
    priority_queue<int,vector<int>, greater<int>> pq2;

    for(int i = 0 ; i < 10; i++ ){
        int num = rand()%100;
        pq2.push(num);
        cout << "insert "<<num<<" in priority queue"<<endl;

    }
    while(!pq2.empty()){
        cout<< pq2.top() <<" ";
        pq2.pop();
    }
    cout<< endl;

    return 0;

}