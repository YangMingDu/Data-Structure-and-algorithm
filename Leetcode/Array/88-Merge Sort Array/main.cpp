#include <vector>
#include <iostream>

using namespace::std;


class Solution {
public:
    //近似于归并排序的merge操作
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> aux;
        int j = 0;
        int k = 0;

        for(int i = 0; i < m; i ++){
            aux.push_back(nums1[i]);
        }

        for(int i = 0; i < (m+n); i ++){
            if(j >= m){
                nums1[i] = nums2[k];
                k++;
            }
            else if( k >= n){
                nums1[i] = aux[j];
                j++;
            }
            else if(nums2[k] > aux[j]){
                nums1[i] = aux[j];
                j++;
            }
            else{
                nums1[i] = nums2[k];
                k++;
            }

        }






    }
};