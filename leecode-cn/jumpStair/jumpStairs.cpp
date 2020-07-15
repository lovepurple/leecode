#include <iostream>
/*
	青蛙爬楼梯问题 dp求解
*/

class Solution
{
public:
	int numWays(int n);
};

int main()
{
	int stairsNum = 41;
	Solution s;
	int ways = s.numWays(stairsNum);

	std::cout << ways;
	return 0;
}

int Solution::numWays(int n)
{
	//每次只能走一阶或两阶，最后一步是可以是 f[i] = f[i-1] + f[i-2]
	//dp[i] 为走到i 步所用的步数 
	//最后一步 = 到最后一步的前一步 + 到最后一步的前两步

	if (n <= 1)
		return 1;

	int* dp = new int[n + 1];
	dp[0] = 1;
	dp[1] = 1;		//n=0时，在gcc上什么有heap buffer overflow的问题

	//int 溢出的问题 除 1000000007
	for (int i = 2; i <= n; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
	}


	return dp[n];
}
