#include <iostream>
#include <algorithm>
#include "Student.h"
#include "SortTestHelper.h"
using namespace :: std;



 /*运用范式编程，可以使数组元素不局限于单一类型*/
template<typename T>
 /*输入为原数组以及元素数量，输出为空*/
void InsertionSort(T arr[],int n){
     /*在[0，n]范围内*/
    for(int i = 1; i < n; i++){
         /*将元素arr[i]插入到合适的位置j*/
        for(int j = i; j > 0; j--){
            if(arr[j-1] > arr[j]){
                swap(arr[j-1],arr[j]);  /*向前插入*/
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

    
    SortTestHelper::TestSort("Insertion Sort",InsertionSort,arrtest1,n);
    SortTestHelper::PrintArray(arrtest1,n);

    delete[] arrtest1;


    return 0;
}