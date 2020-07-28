#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
	相对于0-1背包，每个物品的数量没有限制。
		对于01背包 dp[i][j] 表示在 容量=j时，前i件物品最大的价值
			每件物品只能取1次
					dp[i-1][j-w[i]]
					表示不包括当前物品，同时不包括当前重量的价值
		完全背包时，由于一个物品可以取多次（所以需要枚举多次同一物品 算出每一次枚举的），状态转移方程为：
				dp[i][j] = max(dp[i-1][j - k * w[i]] + k * v[i]
				每次枚举出剩余背包的最大价值
			而01背包只关心一件物品即可 （确实就是 k=[0,1]的完全背包 ）
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i])
*/

class Solution
{
public:
	int completelyKnapsack(const vector<int> goodsValues, const vector<int> goodsWeights, const int totalCapacity);
};


int main()
{
	Solution s;
	vector<int> vecGoodsValue = { 12,3,10,3,6 };
	vector<int> vecWeights = { 5,4,7,2,6 };
	int kanpsackCapacity = 10;
	int maxWorth = s.completelyKnapsack(vecGoodsValue, vecWeights, kanpsackCapacity);

	cout << maxWorth;
	return 0;
}

int Solution::completelyKnapsack(const vector<int> goodsValues, const vector<int> goodsWeights, const int totalCapacity)
{
	vector<vector<int>> dp(goodsValues.size() + 1);

	//只有一件商品时，装的越多，价值越高
	dp[0] = vector<int>(totalCapacity + 1);

	for (int j = 1; j <= totalCapacity; ++j)
	{
		for (int k = 0;; k++)
		{
			if (j >= k * goodsWeights[0])
			{
				dp[0][j] = k * goodsValues[0];
			}
			else
				break;
		}
	}



	//dp[i][j] 为j重量下  前i个物品 最大的价值
	for (int i = 1; i < goodsValues.size(); ++i)
	{
		int goodsValue = goodsValues[i];
		int goodsWeight = goodsWeights[i];

		dp[i] = vector<int>(totalCapacity + 1);

		for (int j = 1; j <= totalCapacity; ++j)
		{
			//k循环 选择多少个相同的物品
			for (int k = 0;; k++)
			{
				if (j - k * goodsWeight < 0)
					break;

				dp[i][j] = max(dp[i][j], dp[i - 1][j - k * goodsWeight] + k * goodsValue);
			}
		}
	}

	//最后一个是i-1
	return dp[goodsValues.size() - 1][totalCapacity];
}
