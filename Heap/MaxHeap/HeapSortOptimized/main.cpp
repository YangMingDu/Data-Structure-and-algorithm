#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
#include "MaxHeap.h"
#include "SortTestHelper.h"
#include "QuickSortThreeWays.h"
#include "QuickSort.h"


using namespace :: std;

template<typename T>
void heapSort1(T arr[], int n){

    MaxHeap<T> maxheap = MaxHeap<T>(n);
    for( int i = 0; i < n ; i ++ ){
        maxheap.insert(arr[i]);
    }

    for( int i = n-1 ; i >= 0 ; i-- ){
        arr[i] = maxheap.extractMax();
    }
    
}

/*Heapify*/
template<typename T>
void heapSort2(T arr[], int n){

    MaxHeap<T> maxheap = MaxHeap<T>(arr,n);

    for( int i = n-1 ; i >= 0 ; i-- ){
        arr[i] = maxheap.extractMax();
    }

}

int main(){
    int n = 1000000;

    /*测试无序数组*/
/*     int *arrtest1 = SortTestHelper::generateRandomArray(n,0,n);  */
    /*测试几乎有序数组*/
   int *arrtest1 = SortTestHelper::generateNealyOrderedRandomArray(n,50);
    /*测试结构体*/
  /*Student a[4] = {{"XiaoMing",100},{"DaMing",10},{"ZhongMing",80},{"WeiMing",150}};*/
    /*复制第一组无序数组用于对比优化前后处理时间的区别*/
    int *arrtest2 = SortTestHelper::copyIntArray(arrtest1,n);
    int *arrtest3 = SortTestHelper::copyIntArray(arrtest1,n);
    int *arrtest4 = SortTestHelper::copyIntArray(arrtest1,n);
 

    SortTestHelper::TestSort("Heap Sort1",heapSort1,arrtest1,n); 


    SortTestHelper::TestSort("Quick Sort",QuickSortOptimized,arrtest2,n);

    SortTestHelper::TestSort("Quick Sort Three Ways",ThreeWaysQuickSort,arrtest3,n);

    SortTestHelper::TestSort("Heap Sort1",heapSort2,arrtest4,n); 

    delete[] arrtest1;
    delete[] arrtest2;
    delete[] arrtest3;
    delete[] arrtest4;
  
    cout << endl;


    return 0;
}