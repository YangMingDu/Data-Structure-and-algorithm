#include <iostream>
#include <algorithm>

#include <ctime>
using namespace :: std;


template<typename T>
int __partition(T arr[],int left,int right){

    swap(arr[left],arr[rand()%(right-left+1)+left]);

    T v =arr[left];

    int i;

    /*arr[l+1...j] < v ; arr[j+1...right] > v*/
    int j = left;
    for(i = left+1; i <= right; i++){

      if(arr[i] <= v ){
        swap(arr[i],arr[j+1]);
        j++; 
      } 

    }
    swap(arr[left],arr[j]);

    return j;



}


template<typename T>

void __QuickSort(T arr[],int left,int right){

  if( left > right ){

    return;
  }

  int p = __partition(arr,left,right);
  __QuickSort(arr,left,p-1);
  __QuickSort(arr,p+1,right);

  

}




template<typename T>

void QuickSortOptimized(T arr[],int n){

  srand(time(NULL));


  __QuickSort(arr,0,n-1);

}

 




