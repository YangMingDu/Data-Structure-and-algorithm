#ifndef ALGORITHMSTUDY_SortTestHelper_H
#define ALGORITHMSTUDY_SortTestHelper_H
#include <iostream>
#include <ctime>
#include <cassert>
#include <algorithm>
using namespace :: std;

namespace SortTestHelper{
    /*生成随机数组*/
    int* generateRandomArray(int n,int rangeL, int rangeR){
        assert(rangeL < rangeR);
        int *arr = new int[n];
        srand(time(NULL));
        for(int i = 0; i < n; i++){
            arr[i] = rand() % (rangeR-rangeL + 1) +rangeL;
        }
        return arr;
    }
    /*生成几乎有序的随机数组，先生成有序数组，后进行多次（swaptimes）交换*/
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

    /*打印数组*/
    template<typename T>
    void PrintArray(T arr[], int n)
    {
        for(int i = 0; i < n; i++ ){
        cout<< arr[i] <<" ";
        }
        cout << endl;

        return;       
    }
    
    /*判断是否已经正确排序*/
    template<typename T>
    bool isSorted(T arr[],int n){
        for(int i = 1; i < n; i++){
            if(arr[i] < arr[i - 1])
            return false;
        }
        return true;
    }

    /*复制数组*/
    template<typename T>
    int* copyIntArray(T a[],int n)
    {
        int* arr = new int[n];
        /*copy（原地址首指针，原地址尾指针，复制到地址的首指针）*/
        copy(a,a+n,arr);
        return arr;

    }


    /*测试完成排序时间*/
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