#include <iostream>
#include <algorithm>
#include "Student.h"
#include "SortTestHelper.h"
using namespace :: std;

template<typename T>
 /*输入为原数组以及元素数量，输出为空*/
void InsertionSortOptimized(T arr[],int n){

    for(int i = 1; i < n; i++){
        T e = arr[i];
        int j;
        for(j = i; j > 0 && arr[j-1] > e; j--){
             arr[j] = arr[j-1]; /*找到合适的位置j，在找到合适位置之前将不合适的元素向后移*/
        }
        arr[j] = e; /*找到arr[i]的合适位置，并将arr[j]赋值*/ 
    }
 
}


template<typename T>
void ShellSort(T arr[],int n){

    int gap;/*增量*/ 
    /*增量初始化为数组长度的一半，并每次循环/2进行缩小增量*/ 
    for(gap = n/2; gap > 0; gap /= 2){
      /*对每组进行插入排序*/ 
      for(int i = gap; i < n; i++ ){
        T e = arr[i];
        int j;
        for(j =i - gap;j >= 0 && arr[j] > e; j-=gap){
          arr[j+gap] = arr[j];
        }
        arr[j+gap] = e;
      }

    }


 
}



 




int main(){

  /*测试浮点数*/
    float arr1[10] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.10};
    /*测试字符串*/
    string arr2[4] = {"A","B","C","D"};

    int n = 10000;

    /*测试无序数组*/
    int *arrtest1 = SortTestHelper::generateRandomArray(n,0,n); 
    /*测试几乎有序数组*/
  /*int *arrtest1 = SortTestHelper::generateNealyOrderedRandomArray(n,50);*/
    /*测试结构体*/
  /*Student a[4] = {{"XiaoMing",100},{"DaMing",10},{"ZhongMing",80},{"WeiMing",150}};*/
    /*复制第一组无序数组用于对比优化前后处理时间的区别*/
    int *arrtest2 = SortTestHelper::copyIntArray(arrtest1,n);
    SortTestHelper::TestSort("Insertion Sort Optimized",InsertionSortOptimized,arrtest1,n);
    SortTestHelper::TestSort("Shell Sort",ShellSort,arrtest2,n);
    SortTestHelper::PrintArray(arrtest1,n);

    delete[] arrtest1;
    delete[] arrtest2;


    return 0;




}