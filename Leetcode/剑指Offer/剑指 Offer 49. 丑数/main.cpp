#include <string>
#include <algorithm>
#include <vector>
using namespace :: std;
class Solution {
public:
//首先我们要发现，任何一个丑数，都是可以由其前面的某个丑数乘2，或乘3，或乘5得到。
//我们先建立一个长度为 n 的 dp 数组，dp[i] 表示第 i + 1 个丑数。
//然后我们设立三个变量：two, three, five，它们都代表 dp 数组中的索引。我们通过选取 dp[two] * 2, dp[three] * 3 和 dp[five] * 5 中的最小值来确定下一个丑数的值。
//当找到了下一个丑数后，假如这个丑数是由 two 得来的，我们就 ++ two；假如是由 three 得来的，我们就 ++ three；是由 five 得来的，我们就 ++ five。这样就可以保证每个丑数都会找出来。

	int nthUglyNumber(int n) {
		vector<int> dp(n, 0);
		dp[0] = 1;
		int p2 = 0, p3 = 0, p5 = 0;
		for (int i = 1; i < n; i++) {
			dp[i] = min(min(dp[p2] * 2, dp[p3] * 3), dp[p5] * 5);
			if (dp[i] == dp[p2] * 2)
				p2++;
			if (dp[i] == dp[p3] * 3)
				p3++;
			if (dp[i] == dp[p5] * 5)
				p5++;
		}
		return dp[n - 1];
	}
};
