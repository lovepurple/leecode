#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	Solution();
	~Solution();
	int maxProfit(vector<int>& prices);

	/// <summary>
	/// 2020-09-03 17:29:39  干掉一次循环
	/// </summary>
	/// <param name="prices"></param>
	/// <returns></returns>
	int maxProfitOptimize(vector<int>& prices);

	/// <summary>
	/// 2020-10-15 18:36:36
	/// </summary>
	/// <param name="prices"></param>
	/// <returns></returns>
	int maxProfitDP(vector<int>& prices);
};

Solution::Solution()
{
}

Solution::~Solution()
{
}

int Solution::maxProfit(vector<int>& prices)
{
	int max = 0;
	int maxSaleDay;
	for (vector<int>::iterator it = prices.begin(); it != prices.end(); ++it)
	{
		//C++ 中 获取当前 iterator 的index
		int buyDayIndex = distance(prices.begin(), it);
		for (vector<int>::iterator itSaleDay = prices.begin() + buyDayIndex + 1; itSaleDay != prices.end(); ++itSaleDay)
		{
			int profit = *itSaleDay - *it;
			if (profit > max)
			{
				max = profit;
				maxSaleDay = distance(prices.begin(), itSaleDay);
			}
		}
	}


	return max > 0 ? maxSaleDay + 1 : 0;
}

int Solution::maxProfitOptimize(vector<int>& prices)
{
	return 0;
}

int Solution::maxProfitDP(vector<int>& prices)
{
	/*
		dp[i]为前i 天最大的利润

		dp[i] = max(dp[i-1],price[i] - minpriceBuy)
	*/

	if (prices.size() == 0)
		return 0;

	int minBuyPrice = INT_MAX;
	vector<int> dp(prices.size() + 1);
	dp[0] = 0;

	for (int i = 1; i <= prices.size(); ++i)
	{
		dp[i] = max(dp[i - 1], prices[i - 1] - minBuyPrice);
		minBuyPrice = min(minBuyPrice, prices[i - 1]);
	}


	return dp[prices.size()];
}

int main()
{
	vector<int> prices = { 7,1,5,3,6,4 };
	Solution solution;
	cout << solution.maxProfitDP(prices);

	return 0;
}