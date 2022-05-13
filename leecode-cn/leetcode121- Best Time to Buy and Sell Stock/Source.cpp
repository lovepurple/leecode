#include <iostream>
#include <vector>

using namespace std;

//����Ч��̫��leetcode��ʱ��ʹ��dp
int maxProfit(vector<int>& prices)
{
	if (prices.size() <= 1)
		return 0;

	int left = 0;
	int maxProfits = 0;
	while (left < prices.size())
	{
		int right = left + 1;
		while (right < prices.size())
		{
			maxProfits = max(maxProfits, prices[right] - prices[left]);

			right++;
		}

		left++;
	}

	return maxProfits;
}


int maxProfitDP(vector<int>& prices)
{
	//dp[n] ǰn��������������
	//������ = ����۸� - ǰЩ���������
	if (prices.size() <= 1)
		return 0;

	int* dp = new int[prices.size() + 1];
	dp[0] = 0;
	dp[1] = 0;

	int minBuyPrice = prices[0];
	int maxProfits = 0;

	for (int i = 1; i < prices.size(); ++i)
	{
		int todayPrice = prices[i];
		maxProfits = max(maxProfits, todayPrice - minBuyPrice);
		dp[i + 1] = max(maxProfits, dp[i]);

		minBuyPrice = min(minBuyPrice, todayPrice);
	}

	return dp[prices.size()];
}


int main()
{
	vector<int> prices = { 7,1,5,3,6,4 };

	cout << maxProfitDP(prices);

	return 0;
}