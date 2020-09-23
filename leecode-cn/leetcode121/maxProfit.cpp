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

int main()
{
	vector<int> prices = { 1,2 };
	Solution solution;
	cout << solution.maxProfit(prices);

	return 0;
}