#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "MergeSort.h"
using namespace :: std;




template<typename T>

void MergeSortBU(T arr[],int n){

  for(int size = 1; size <= n ;size += size){

    for(int i = 0; i + size < n; i += size + size){
      /*对arr[i...i+size-1]和arr[i+size...i+2*size-1]进行归并*/
      
      __Merge(arr , i ,i + size - 1,min(i + size + size - 1 ,n-1));
    }
  }

 
}



int main(){

  /*测试浮点数*/
    float arr1[10] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.10};
    /*测试字符串*/
    string arr2[4] = {"A","B","C","D"};

    int n = 100000;

    /*测试无序数组*/
    int *arrtest1 = SortTestHelper::generateRandomArray(n,0,n); 
    /*测试几乎有序数组*/
  /*int *arrtest1 = SortTestHelper::generateNealyOrderedRandomArray(n,50);*/
    /*测试结构体*/
  /*Student a[4] = {{"XiaoMing",100},{"DaMing",10},{"ZhongMing",80},{"WeiMing",150}};*/
    /*复制第一组无序数组用于对比优化前后处理时间的区别*/
    int *arrtest2 = SortTestHelper::copyIntArray(arrtest1,n);

    SortTestHelper::TestSort("Merge Sort BU",MergeSortBU,arrtest1,n);

    delete[] arrtest1; 


    return 0;




}