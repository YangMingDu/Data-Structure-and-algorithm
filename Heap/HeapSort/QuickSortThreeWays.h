#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace :: std;




template<typename T>

void __ThreeWaysQuickSort(T arr[],int left,int right){

  if( left > right ){
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

 



