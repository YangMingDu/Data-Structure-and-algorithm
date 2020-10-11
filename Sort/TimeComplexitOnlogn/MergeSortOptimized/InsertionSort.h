#ifndef MERGESORTOPTIMIZED_INSERTIONSORT_H
#define MERGESORTOPTIMIZED_INSERTIONSORT_H


#include <iostream>
#include <algorithm>
#include "Student.h"
#include "SortTestHelper.h"
using namespace :: std;

template<typename T>
void InsertionSort(T arr[],int left,int right){

    for(int i = left + 1; i <= right; i++){
        T e = arr[i];
        int j;
        for(j = i; j > left  && arr[j-1] > e; j--){
             arr[j] = arr[j-1]; /*找到合适的位置j，在找到合适位置之前将不合适的元素向后移*/
        }
        arr[j] = e; /*找到arr[i]的合适位置，并将arr[j]赋值*/ 
    }
 
}

template<typename T>
void InsertionSort(T arr[],int n){

    for(int i = 1; i < n; i++){
        T e = arr[i];
        int j;
        for(j = i; j > 0  && arr[j-1] > e; j--){
             arr[j] = arr[j-1]; /*找到合适的位置j，在找到合适位置之前将不合适的元素向后移*/
        }
        arr[j] = e; /*找到arr[i]的合适位置，并将arr[j]赋值*/ 
    }
 
}

#endif
