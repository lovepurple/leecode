#include <iostream>
#include <vector>
#include <algorithm>

/*
	https://leetcode-cn.com/problems/coin-change/
	完全背包问题
*/
using namespace std;

class Solution
{
public:
	int coinChange(vector <int>& coins, int amount);
};


int main()
{
	Solution s;
	vector<int> coins = { 2,5,10,1 };
	int amount = 27;

	int minCoinNum = s.coinChange(coins, amount);
	cout << minCoinNum << endl;


	return 0;
}

int Solution::coinChange(vector<int>& coins, int amount)
{

	vector<int> dp(amount + 1);
	dp[0] = 0;

	//由于是计算min 所以无法组成时，使用INT_MAX 比较方便
	for (int j = 1; j <= amount; ++j)
	{
		dp[j] = j % coins[0] == 0 ? j / coins[0] : INT_MAX;
	}

	for (int i = 1; i < coins.size(); ++i)
	{
		int coinVal = coins[i];

		for (int j = coinVal; j <= amount; ++j)
		{
			if (dp[j - coinVal] != INT_MAX)
				dp[j] = min(dp[j], dp[j - coinVal] + 1);			//+1 表示 加上当前的

		}
	}



	return dp[amount] == INT_MAX ? -1 : dp[amount];
}
