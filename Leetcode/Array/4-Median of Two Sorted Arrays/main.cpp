#include <vector>
using namespace :: std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();
        int count = 0;
        int leftPointer = 0;
        int rightPointer = 0;
        double arr[2000];
        double res = 0;
        if(!m && !n){
            return 0;
        }

        if ((m + n)%2 != 0 ){
            //类似merge
            while(count != (m+n)/2 + 1){
                if(rightPointer > n - 1){
                    res = nums1[leftPointer];
                    leftPointer ++;
                    count ++;
                }

                else if(leftPointer > m - 1){
                    res = nums2[rightPointer];
                    rightPointer ++;
                    count++;
                }

                else if(nums1[leftPointer] < nums2[rightPointer]){
                    res = nums1[leftPointer];
                    leftPointer ++;
                    count ++;
                    
                }
                else{
                    res = nums2[rightPointer];
                    rightPointer ++;
                    count ++;
                    
                }

            }

        }
        else{
        while(count != (m+n)/2 + 1){
                if(rightPointer > n - 1){
                    arr[count] = nums1[leftPointer];
                    leftPointer ++;
                    count ++;
                }

                else if(leftPointer > m - 1){
                    arr[count] = nums2[rightPointer];
                    rightPointer ++;
                    count++;
                }

                else if(nums1[leftPointer] < nums2[rightPointer]){
                    arr[count] = nums1[leftPointer];
                    leftPointer ++;
                    count ++;
                    
                }
                else{
                    arr[count] = nums2[rightPointer];
                    rightPointer ++;
                    count ++;
                    
                }

            }
        
        res = (arr[count-2] + arr[count - 1])/2;
        }
        return res;

    }
};