#include <iostream>
#include <vector>
#include <map>

using namespace ::std;

vector<int> FinallyWay(int n,vector<vector<int>> &nums){
    vector<int> res;
    map<int,int> record;
    for(int i = 1; i < n + 1; i++){
        record[i] ++;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j< n; j++){
            if(record[nums[i][j]] > 0){
                res.push_back(nums[i][j]);
                record[nums[i][j]] --;
                break;

            }
            
        }
    }
    return res;
    
}


int main(){
    int n;
    vector<vector<int>> mumbers;

    cin>>n;


	vector<vector<int>>array;//定义二维数组
	vector<int>v;//定义一维数组
	array.clear();//将二维数组清空，或初始化（初始化代码很简单，不会可以百度）//也可不用这一步
	int temp=0;
	for (int i = 0; i < n; i++)//输入r*c的二维数组
	{
		v.clear();//子数组返回时要清除
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			v.push_back(temp);
 
		}
		array.push_back(v);
	}

    vector<int> res;
    
    res = FinallyWay(n,array);
    for(int i = 0 ; i < n; i++){
        cout<<res[i]<<" ";
    }
    
    return 0;
}