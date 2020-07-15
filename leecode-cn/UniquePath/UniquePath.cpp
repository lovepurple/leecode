#include <iostream>
#include <vector>
/*
	机器人走格子问题，最基本的动态规划。  找到最后一步和上一步的联系推到出递推公司dp[]，然后填充dp的初始值，因为下一步需要上一步的结果 一个错都错。
		对于dp[]怎么设，一般是怎么问怎么设 
		例如本题，问走到格式i,j需要多少种方式，设dp[i][j] 为走到i,j需要多少种方式

*/

using namespace std;

class Solution
{
public:
	int waysToDst(int mapX, int mapY, int dstX, int dstY);
};

int main()
{
	int mapX = 3;
	int mapY = 5;

	Solution s;
	int ways = s.waysToDst(mapX, mapY, 3, 5);

	cout << ways;


	return 0;
}

int Solution::waysToDst(int mapX, int mapY, int dstX, int dstY)
{
	vector<vector<int>> dp(mapX);

	for (int i = 0; i < mapX; ++i)
	{
		dp[i] = vector<int>(mapY);
		for (int j = 0; j < mapY; ++j)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 1;
		}
	}

	for (int i = 1; i <= dstX - 1; i++)
	{
		for (int j = 1; j <= dstY - 1; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}


	return dp[dstX - 1][dstY - 1];
}
