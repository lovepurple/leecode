/*
	换硬币问题，DP

	硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007)
	https://leetcode-cn.com/problems/coin-lcci/

	2020-07-21 16:17:06：
		与ChangeCoin1不一样，ChangeCoin是求最小，只求一个数，而本题是求状态，是什么完全背包问题
			for 状态1 in 状态1的所有取值：
				for 状态2 in 状态2的所有取值：
					for ...
						dp[状态1][状态2][...] = 计算(选择1，选择2...)

	2020-07-28 18:35:09
		完全背包问题
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int waysToChange(int n);

	int waysToChangeOptimized(int n);

	int change(int amount, vector<int>& coins);

	const vector<int> CoinList = { 25,10,5,1 };


};


int main()
{
	Solution s;
	int n = 5;

	int ways = s.waysToChange(n);

	cout << ways << endl;

	int ways2 = s.waysToChangeOptimized(n);
	cout << ways2 << endl;

	vector<int> coins = { 1,2,5 };
	int ways3 = s.change(n, coins);

	return 0;
}

int Solution::waysToChange(int n)
{
	/*
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
		/ *
			错误方式：
				for(1~i)
					for( coin:coins）

				当n =6时，


				f[6] = f[5] + f[1]
				同时
				f[6] = f[1] + f[5] 这样就被重复计算，导致结果不正确

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

				解决方法：外层使用for(coin :coins)
						内层		for(i->n)
			* /


			以上为没掌握完全背包问题解答。。。。
			2020-07-28 18:36:38

	*/

	/*状态转移方程 :
		dp[i][j] 使用前i种硬币，组成总金额为j 的表示法
	   dp[i][j] = dp[i-1][j] + dp[i][j - coin[i]]
				= 不使用当前 + 使用上一次剩余的价值 使用当前

	*/

	vector<vector<int>> dp(n + 1);

	for (int i = 0; i < CoinList.size(); ++i)
	{
		dp[i] = vector<int>(n + 1);

		//初始始的问题 dp[i][0] = 1 每一行的第一个数都为1
		dp[i][0] = 1;

		for (int j = 1; j <= n; ++j)
		{
			if (j - CoinList[i] >= 0)
				dp[i][j] = dp[i - 1][j] + dp[i][j - CoinList[i]];
		}
	}

	return dp[CoinList.size() - 1][n];


}

/// <summary>
/// 一维数组优化版
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
/// 将dp[i][j] 降维
///				[i] 表示前i 个物品组成的结果，而最后i一定是最后一个， 可直接使用dp[j]  每一次使用上一次的i
int Solution::waysToChangeOptimized(int n)
{
	vector<int> dp(n + 1);

	dp[0] = 1;

	for (int i = 0; i < CoinList.size(); ++i)
	{

		for (int j = 1; j <= n; ++j)
		{
			if (j - CoinList[i] >= 0)
			{
				/*降低为一维时， dp[j] 是上一次不包括当前 coin[i]的结果
				本例中：
					当 coin = 1时
					dp[5] 是上一次的coin = 5时的情况
					dp[5] = dp[5] + dp[5-1]
					更新后的dp[5] 是包括coin = 1的情况。

				更新顺序为正序 dp[4] 是包括当前coin

				*/
				dp[j] += dp[j - CoinList[i]];
			}
		}
	}


	return dp[n];
}

int Solution::change(int amount, vector<int>& coins)
{
	vector<int> vecDp(amount + 1);

	vecDp[0] = 1;			//初始化dp[0]
	for (int i = 0; i < coins.size(); ++i)
	{
		int coinValue = coins[i];

		/*
			//这里可以优化的点  j的起始值在 < coinvalue时，dp[j] 不需要更新
			因此 j=coinvalue[i] to amount 也可以，减少一部分if

			for(int j = coinvalue;j<=amount ;++j)
				vecDp[j] = vecDp[j] + vecDp[j-CoinValue];

				todo:
					耗时会有明显减少
						20ms -> 12ms

		*/
		for (int j = 1; j <= amount; ++j)
		{
			if (j - coinValue >= 0)
				vecDp[j] = vecDp[j] + vecDp[j - coinValue];
		}
	}

	return vecDp[amount];
}
