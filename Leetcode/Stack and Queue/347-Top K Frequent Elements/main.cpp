#include<queue>
#include<unordered_map>
#include<iostream>
#include<vector>

using namespace :: std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //第一个int是元素，第二个是他出现的频率
        unordered_map<int,int> Freq;
        for(int i = 0 ; i < nums.size(); i++){
            Freq[nums[i]] += 1;
        }
        //pair<int,int> pair<频率，元素>因为要创建最小堆的优先队列，要比较的是频率，所以将pair中第一个int设为频率。
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for( unordered_map<int,int>::iterator iter = Freq.begin(); iter != Freq.end() ; iter++){

            if(pq.size() == k){
                if(iter->second > pq.top().first){
                    pq.pop();
                    pq.push(make_pair(iter->second,iter->first));
                }
            }

            else{
                pq.push(make_pair(iter->second,iter->first));
            }


        }

        vector<int> res;
        while(!pq.empty()){
            res.insert(res.begin(),pq.top().second);
            pq.pop();
        }

        return res;



    }
};