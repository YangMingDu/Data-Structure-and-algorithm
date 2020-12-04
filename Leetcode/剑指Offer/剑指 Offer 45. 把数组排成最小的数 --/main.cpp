#include <string>
#include <algorithm>
#include <vector>
using namespace :: std;
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        string res;
        for(auto num:nums)
            strs.push_back(to_string(num));
        sort(strs.begin(),strs.end(),compare);
        for(auto str:strs)
            res+=str;
        return res;
    }
private:
    static bool compare(const string &a,const string &b)
    //字符串类型的数字比较大小是从第一位开始比较其在字符编码中对应的数值大小，相等则继续比较第二位，不相等就是数值大的为大
    //所以"330">"303"
    {
        return a+b<b+a;
    }
};