#include <iostream>
#include <vector>
#include <unordered_map>
using namespace :: std;
class Solution {
public:
    //利用哈希表解决问题，利用另外两个点到一个点的距离的平方当做key，用不同的距离的点数作为value，计算相同距离的点。
    int distance(vector<int>& p1,vector<int>& p2){
        int dis = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
        return dis;
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for( int i = 0 ; i < points.size() ; i ++){
            unordered_map<int,int> record;
            for(int j = 0; j < points.size() ; j ++){
                if(j != i){
                    record[distance(points[i],points[j])] ++ ;
                }
            }

            for(unordered_map<int,int>::iterator iter = record.begin(); iter != record.end(); iter ++){
                if(iter -> second >= 2){
                    res += (iter->second) * (iter->second-1);
                }
            }

        }

        return res;


    }


};