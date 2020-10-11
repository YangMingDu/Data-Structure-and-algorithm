#include <iostream>
#include <algorithm>

using namespace :: std;

template<typename T>
 /*输入为原数组以及元素数量，输出为空*/
void InsertionSortOptimized(T arr[],int left,int right){

    for(int i = left+1; i < right; i++){
        T e = arr[i];
        int j;
        for(j = i; j > 0 && arr[j-1] > e; j--){
             arr[j] = arr[j-1]; /*找到合适的位置j，在找到合适位置之前将不合适的元素向后移*/
        }
        arr[j] = e; /*找到arr[i]的合适位置，并将arr[j]赋值*/ 
    }
 
}