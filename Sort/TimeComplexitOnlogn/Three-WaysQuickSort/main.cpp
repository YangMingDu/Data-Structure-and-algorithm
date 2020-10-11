#include <iostream>
#include <algorithm>
#include "Student.h"
#include "SortTestHelper.h"
#include "InsertionSort.h"
#include <ctime>
using namespace :: std;




template<typename T>

void __ThreeWaysQuickSort(T arr[],int left,int right){

  if( right - left < 10 ){
    InsertionSortOptimized(arr,left,right);
    return;
  }
    /*partition*/

    swap(arr[left],arr[rand()%(right-left+1)+left]);

    T v =arr[left];

    int lt,gt,i;

    lt = left;
    gt = right + 1;
    i = left + 1;

    while(i < gt){ 
      if(arr[i] < v){
        swap(arr[i],arr[lt + 1]);
        i++;
        lt ++;
        }
      else if(arr[i] > v){
        swap(arr[i],arr[gt-1]);
        gt--;
      }
      else{
        i++;
      }

      
    }

    swap(arr[left],arr[lt]);

  __ThreeWaysQuickSort(arr,left,lt-1);
  __ThreeWaysQuickSort(arr,gt,right);

}




template<typename T>

void ThreeWaysQuickSort(T arr[],int n){

  srand(time(NULL));


  __ThreeWaysQuickSort(arr,0,n-1);

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
    SortTestHelper::TestSort("Quick Sort",ThreeWaysQuickSort,arrtest1,n);


    delete[] arrtest1;



    return 0;




}