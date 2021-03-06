#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>


using namespace :: std;


template<typename Item>
class MaxHeap{

private:

    Item* data;
    int count;
    int capacity;

    void shiftUp(int k){
        while(data[k/2] < data[k] && k > 1){
            swap(data[k/2],data[k]);
            k /= 2;
        }
    }

    void shiftDown(int k){
        while(2*k <= count){

            int j = 2*k;
            if (j+1 <= count && data[j+1]>data[j]){
                j++;
            }
            if(data[k]>=data[j]){
                break;
            }
            swap(data[j],data[k]);
            k = j;

        }
    }
    
public:
    /*capacity 容量*/
    MaxHeap(int capacity){
        data = new Item[capacity+1];/*因为本次堆的索引从1开始*/
        count = 0;
        this->capacity = capacity;
    }

    MaxHeap(Item arr[],int n){

        data = new Item[n+1];
        capacity = n;
        for(int i = 0; i < n;i++){
            data[i+1] = arr[i];
        }
        count = n;

        for( int i = count/2 ;i >= 1; i--){
            shiftDown(i);
        } 

    }

    ~MaxHeap(){
        delete[] data;
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }

    void insert(Item item){

        assert(count + 1 <= capacity);
        data[count + 1] = item;
        count ++;
        shiftUp(count);
    }

    Item extractMax(){
        assert( count > 0);
        Item ret = data[1];

        swap(data[1],data[count]);
        count --;
        shiftDown(1);
        return ret;
    }

};
   