#include <iostream>
#include <algorithm>
#include <vector>

using namespace :: std;

class Solution{
public:
    int findContentChildren(vector<int>& g,vector<int>& s){

        /*从大到小排序*/

        sort(g.begin(),g.end(),greater<int>());
        sort(s.begin(),s.end(),greater<int>());

        /*i为小朋友的索引，j为饼干的索引，res为满足的小朋友的数量*/

        int i = 0;
        int j = 0;
        int res = 0;

        /*边界为小朋友个数和饼干个数*/

        while(i < g.size() && j < s.size()){

            /*如果饼干大小大于等于贪心指数，那么就将这个饼干给这个小朋友，满足小朋友个数加1，饼干和小朋友都换成下一个*/

            if (s[i] >= g[j]){
                res ++;
                i++;
                j++;
            }
            /*如果饼干大小小于贪心指数，那么不能满足这个小朋友，小朋友换下一个*/
            else{

                i++;

            }





        }
        return res;


    }    


};

int main(){

    return 0;
}