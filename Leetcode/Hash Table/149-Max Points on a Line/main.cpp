#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace :: std;
class Solution {
int gcd(int a,int b){
    while(b != 0){
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() < 3){
            return points.size();
        }
        int res = 0;
        //遍历每个点
        for(int i = 0;i<points.size();i++){
            int duplicate = 0;//重复点
            int max_t = 0;//保存经过当前点的直线中，最多的点
            unordered_map<string,int> hash;
            for(int j = i+1;j<points.size();j++){
                //求分子分母
                int x = points[j][0] - points[i][0];
                int y = points[j][1] - points[i][1];
                if(x == 0 && y == 0){
                    duplicate++;
                    continue;
                }
                //约分
                int gcd_t = gcd(x,y);
                x = x/gcd_t;
                y = y/gcd_t;
                string key = to_string(x)+"@"+to_string(y);
                hash[key]++;
                max_t = max(max_t,hash[key]);
            }
            res = max(res,max_t+duplicate+1);
        }
        return res;
    }
};
