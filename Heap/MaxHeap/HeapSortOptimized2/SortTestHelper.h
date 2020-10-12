#ifndef ALGORITHMSTUDY_SortTestHelper_H
#define ALGORITHMSTUDY_SortTestHelper_H
#include <iostream>
#include <ctime>
#include <cassert>
#include <algorithm>
using namespace :: std;

namespace SortTestHelper{
    int* generateRandomArray(int n,int rangeL, int rangeR){
        assert(rangeL < rangeR);
        int *arr = new int[n];
        srand(time(NULL));
        for(int i = 0; i < n; i++){
            arr[i] = rand() % (rangeR-rangeL + 1) +rangeL;
        }
        return arr;
    }

    int* generateNealyOrderedRandomArray(int n, int swaptimes){
        int *arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = i;
        }
        srand(time(NULL));
        for(int i = 0; i < swaptimes; i++){
            int posx = rand()%n;
            int posy = rand()%n;
            swap(posx,posy);
        }
        return arr;
    }


    template<typename T>
    void PrintArray(T arr[], int n)
    {
        for(int i = 0; i < n; i++ ){
        cout<< arr[i] <<" ";
        }
        cout << endl;

        return;       
    }
    
    template<typename T>
    bool isSorted(T arr[],int n){
        for(int i = 1; i < n; i++){
            if(arr[i] < arr[i - 1])
            return false;
        }
        return true;
    }


    template<typename T>
    int* copyIntArray(T a[],int n)
    {
        int* arr = new int[n];
        /*copy（原地址首指针，原地址尾指针，复制到地址的首指针）*/
        copy(a,a+n,arr);
        return arr;

    }



    template<typename T>
    void TestSort(string SortName,void(*sort)(T[],int), T arr[], int n){
        
        clock_t startTime = clock();
        sort(arr,n);
        clock_t endTime = clock();

        assert( isSorted(arr,n) );
        cout<< SortName << ":" << double(endTime - startTime)/ CLOCKS_PER_SEC << "s" <<endl; 
        return;

    }



}

#endif