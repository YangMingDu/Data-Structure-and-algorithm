#include <iostream>
#include <algorithm>
#include "Student.h"
#include "SortTestHelper.h"
using namespace :: std;


template<typename T>
int __partition2(T arr[],int left,int right){



    swap(arr[left],arr[rand()%(right-left+1)+left]);

    T v =arr[left];

    int i,j;

    i = left +1;
    j = right;

    while(true){
      while(arr[i] < v && i <= right) i++;
      while(arr[j] > v && j >= left+1) j--;

 
      if( i > j ){
        break;
      }

      swap(arr[i],arr[j]);
      i++;
      j--;

    }


    swap(arr[left],arr[j]);

    return j;



}


template<typename T>

void __TwoWayQuickSort(T arr[],int left,int right){

  if( left >= right ){
    return;
  }

  int p = __partition2(arr,left,right);
  __TwoWayQuickSort(arr,left,p-1);
  __TwoWayQuickSort(arr,p+1,right);

  

}




template<typename T>

void TwoWayQuickSort(T arr[],int n){
  srand(time(NULL));

  __TwoWayQuickSort(arr,0,n-1);

}

 




int main(){

  /*测试浮点数*/
    float arr1[10] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.10};
    /*测试字符串*/
    string arr2[4] = {"A","B","C","D"};

    int n = 1000000;

    /*测试无序数组*/
    int *arrtest1 = SortTestHelper::generateRandomArray(n,0,n); 
    /*测试几乎有序数组*/
  /*int *arrtest1 = SortTestHelper::generateNealyOrderedRandomArray(n,50);*/
    /*测试结构体*/
  /*Student a[4] = {{"XiaoMing",100},{"DaMing",10},{"ZhongMing",80},{"WeiMing",150}};*/
    /*复制第一组无序数组用于对比优化前后处理时间的区别*/
    int *arrtest2 = SortTestHelper::copyIntArray(arrtest1,n);
    SortTestHelper::TestSort("Two Way Quick Sort",TwoWayQuickSort,arrtest1,n);


    delete[] arrtest1;


    return 0;




}