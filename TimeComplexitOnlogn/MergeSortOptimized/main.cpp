#include <iostream>
#include <algorithm>
#include "Student.h"
#include "SortTestHelper.h"
#include "InsertionSort.h"
using namespace :: std;






/*将arr[left到mid]和arr[mid+1到right]两部分进行归并*/
template<typename T>
void __Merge( T arr[] ,int left, int mid,int right ){
  /*申请空间为当前arr大小*/
  T aux[right-left+1];

  for(int i = left; i <= right; i++ ){
    aux[i-left] = arr[i];
  }
  /*i,j分别指向两边边有序数组当前考虑元素的索引，初始化为左边第一个元素的索引以及右边第一个元素的索引*/
  int i = left,j = mid + 1;
  /*k为归并的最终数组的索引，也就是比较i，j所指向元素的大小之后，最终放入arr的元素的索引*/
  for(int k = left;k <= right; k++ ){
  /*当左边的元素都已经放到arr数组中了，只剩下右边的元素了，那么就直接将右侧的元素放入arr中（因为左右都已经是有序数列）。*/
    if(i > mid){
      arr[k] = aux[j-left];
      j++;
    }
     /*反之右边*/
    else if (j > right)
    {
      arr[k] = aux[i-left];
      i++;
    }
    /*当左边的元素小于右边的元素时，将左边的元素放入arr中，且将索引+1*/
    else if(aux[i-left] < aux[j-left]){
      arr[k] = aux[i-left];
      i++;
    }
    /*反之右边*/
    else{
      arr[k] = aux[j-left];
      j++;
    }
    
  }

}






template<typename T>
void __MergeSort( T arr[] ,int left, int right ){
  /*递归终点，当输入左边的值大于右边的值，也就是说mid不能跑到left的左边，mid+1也不能跑到right右边*/

  /*优化：当分半分得已经很小时，出现有序数组的几率会比较大，这样使用插入排序会更快！*/
  

  if((right - left) <= 10 ){
    InsertionSort(arr,left,right);
    return;
  }
  /*当right和left很大的时候可以防止溢出mid = （l+r）/2*/
  int mid =left + (right - left)/2;
  /*递归分组，每次都将数组分为两半进行归并排序，最后剩下left和right只有一个元素的情况*/
  __MergeSort( arr ,left, mid);
  __MergeSort( arr ,mid+1, right);
  /*归并算法*/


  /*优化：如果mid值小于等于mid+1的值时我们可以认为这个数组已经有序那么就不用进行这一轮的merge操作*/

  if(arr[mid] > arr[mid+1]){
    __Merge( arr, left, mid, right);
  }


  

}






template<typename T>

void MergeSort(T arr[],int n){

  __MergeSort( arr ,0, n-1 );
 
}




 




int main(){

  /*测试浮点数*/
    float arr1[10] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.10};
    /*测试字符串*/
    string arr2[4] = {"A","B","C","D"};

    int n = 100000;

    /*测试无序数组*/
    int *arrtest1 = SortTestHelper::generateRandomArray(n,0,n); 
    /*测试几乎有序数组*/
  /*int *arrtest1 = SortTestHelper::generateNealyOrderedRandomArray(n,50);*/
    /*测试结构体*/
  /*Student a[4] = {{"XiaoMing",100},{"DaMing",10},{"ZhongMing",80},{"WeiMing",150}};*/
    /*复制第一组无序数组用于对比优化前后处理时间的区别*/
    int *arrtest2 = SortTestHelper::copyIntArray(arrtest1,n);
    SortTestHelper::TestSort("Merge Sort",MergeSort,arrtest1,n);

    delete[] arrtest1;
    delete[] arrtest2;


    return 0;




}