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
#include "heapSort.h"


using namespace :: std;

template<typename T>
void __shiftDown(T arr[], int n, int k){

            while(2*k + 1 < n){

            int j = 2*k + 1;
            if (j+1 < n && arr[j+1]>arr[j]){
                j += 1;
            }
            if(arr[k] >= arr[j]){
                break;
            }
            swap(arr[j],arr[k]);
            k = j;

        }
}




template<typename T>
void heapSort(T arr[], int n){
    

    for( int i = (n-1-1)/2 ; i >= 0 ; i-- ){
        __shiftDown(arr,n,i);
    }

    for(int i = n-1; i > 0;i--){
        swap(arr[0],arr[i]);
        __shiftDown(arr,i,0);

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
    int *arrtest5 = SortTestHelper::copyIntArray(arrtest1,n);
 

    SortTestHelper::TestSort("Heap Sort",heapSort,arrtest1,n); 
    SortTestHelper::TestSort("Heap Sort1",heapSort1,arrtest2,n); 
    SortTestHelper::TestSort("Heap Sort2",heapSort2,arrtest3,n); 


    SortTestHelper::TestSort("Quick Sort",QuickSortOptimized,arrtest4,n);

    SortTestHelper::TestSort("Quick Sort Three Ways",ThreeWaysQuickSort,arrtest5,n);



    delete[] arrtest1;
    delete[] arrtest2;
    delete[] arrtest3;
    delete[] arrtest4;
    delete[] arrtest5;
  
    cout << endl;


    return 0;
}