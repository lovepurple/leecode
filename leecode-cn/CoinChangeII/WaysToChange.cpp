/*
	换硬币问题，DP

	硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007)
	https://leetcode-cn.com/problems/coin-lcci/
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int waysToChange(int n);


	const vector<int> CoinList = { 25,10,5,1 };


};


int main()
{
	Solution s;
	int n = 10;

	int ways = s.waysToChange(n);

	cout << ways;

	return 0;
}

int Solution::waysToChange(int n)
{
	int* dp = new int[n + 1];
	dp[0] = 1;			//边界问题，最后是ways+1 所以dp[0]=0否则会多一个
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 1;

	if (n <= 4)
		return 1;

	//递推公式： f[n] = f[n-25] + f[n-10] + f[n-5] + f[n-1]
	//f[n] 为拼出总数量为n 的钱数 所需的方式
	/*
		错误方式：
			for(1~i) 
				for( coin:coins）

			当n =6时，
			f[6] = f[5] + f[1] 
	
	*/

	for (int i = 5; i <= n; ++i)
	{

		int ways = INT_MAX;
		for (vector<int>::const_iterator iter = CoinList.begin(); iter != CoinList.end(); ++iter)
		{
			if (i - *iter < 0)
				continue;

			int stepWays = dp[i - *iter];
			if (stepWays < INT_MAX)
			{
				if (ways == INT_MAX)
					ways = stepWays;
				else
					ways += stepWays;
			}
		}

		dp[i] = ways;
	}



	return dp[n];
}
