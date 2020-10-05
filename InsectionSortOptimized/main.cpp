#include <iostream>
#include <algorithm>
#include "Student.h"
#include "SortTestHelper.h"
using namespace :: std;


 /*运用范式编程，可以使数组元素不局限于单一类型*/
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
void InsertionSort(T arr[],int n){
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0; j--){
            if(arr[j-1] > arr[j]){
                swap(arr[j-1],arr[j]);
            }
            else
                break;
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
    SortTestHelper::TestSort("Insertion Sort",InsertionSort,arrtest1,n);
    SortTestHelper::TestSort("Insertion Sort Optimized",InsertionSortOptimized,arrtest2,n);
    SortTestHelper::PrintArray(arrtest1,n);

    delete[] arrtest1;
    delete[] arrtest2;


    return 0;




}