#include <iostream>
#include <algorithm>
#include "Student.h"
#include "SortTestHelper.h"
using namespace :: std;

template<typename T>
 /*运用泛式编程，可以使数组元素不局限于单一类型*/
void SelectionSort(T arr[],int n){
    for(int i = 0; i < n; i ++ ){
         /*最小元素的索引，初始化为i*/
        int MinIndex = i;
        for(int j = i + 1; j < n; j ++ ){
            if (arr[MinIndex] > arr[j]){
                MinIndex = j; /*找到比arr[i]更小的元素时，更改索引值，使当前元素成为最小元素，最终找到最小元素*/
            }
        }
        swap(arr[i],arr[MinIndex]); /*最小元素与当前第一个元素进行交换*/
       
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

    SortTestHelper::TestSort("Insertion Sort",SelectionSort,arrtest1,n);
    
    SortTestHelper::PrintArray(arrtest1,n);

    delete[] arrtest1;
 





    return 0;
}