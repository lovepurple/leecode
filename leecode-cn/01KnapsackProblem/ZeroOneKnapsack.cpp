#include <iostream>
#include <vector>
#include <algorithm>
/*
	0-1背包问题  考虑的是和不装当前物品 带来的影响

	0-1 背包问题特点是每个物品只有一个。

	外层循环是物品列表，内层循环是容量大小
*/
using namespace std;
#include "ZeroOneKnapsackOptimized.h"

class Solution
{
public:
	/// <summary>
	/// 0-1背包求解最大价值
	/// </summary>
	/// <param name="goodsValues">商品价格列表</param>
	/// <param name="goodsWeights">商品重量列表</param>
	/// <param name="capacity">总背包容量</param>
	/// <returns></returns>
	int zeroOneMaxValue(const vector<int> goodsValues, const vector<int> goodsWeights, const int capacity);

	int getDpValue(const vector<vector<int>> dp, int goodsValue, int capacity);
};


int main()
{
	Solution s;
	vector<int> vecGoodsValue = { 12,3,10,3,6 };
	vector<int> vecWeights = { 5,4,7,2,6 };
	int kanpsackCapacity = 10;

	std::cout << s.zeroOneMaxValue(vecGoodsValue, vecWeights, kanpsackCapacity) << std::endl;
	std::cout << "=========================================" << std::endl;

	ZeroOneKnapsackOptimized s1;
	std::cout << s1.ZeroOneKnapsack(vecGoodsValue, vecWeights, kanpsackCapacity);


	return 0;
}

int Solution::zeroOneMaxValue(const vector<int> goodsValues, const vector<int> goodsWeights, const int capacity)
{
	//dp[i][j] 前i件商品，在j容量下的最大价值
	vector<vector<int>> dp(goodsValues.size() + 1);

	//外层循环控制装几个物品

	for (vector<int>::const_iterator itGoodsValue = goodsValues.begin(); itGoodsValue != goodsValues.end(); ++itGoodsValue)
	{
		int indexOfGoods = distance(goodsValues.begin(), itGoodsValue);
		dp[indexOfGoods] = vector<int>(capacity + 1);

		int currentGoodsWeight = goodsWeights[indexOfGoods];

		for (int j = 1; j <= capacity; ++j)
		{
			//装不下当前r物品
			if (j < currentGoodsWeight)
			{
				int valueNotIncludeCurrent = getDpValue(dp, indexOfGoods - 1, j);
				dp[indexOfGoods][j] = valueNotIncludeCurrent;
			}
			else
			{
				//如果装当前，产生的结果,上一个商品和+当前商品
				/*
					dp[i-1][j-currentGoodsWeight]
					理解：
						dp[i][j] 是在容量为j下，前i个物品的最大价值

							j 表示的是枚举到的当前背包大小
							j - currentWeight表示不包括当前物品的背包大小，
							d[i-1][j - currentWeight] 指的是，不包括当前物品，也不包括当前背包大小时的 价值.
				*/
				int valueNotIncludeCurrent = getDpValue(dp, indexOfGoods - 1, j - currentGoodsWeight);
				int newValues = valueNotIncludeCurrent + *itGoodsValue;

				dp[indexOfGoods][j] = max(newValues, getDpValue(dp, indexOfGoods - 1, j));

			}

		}
	}


	//递推表最后一个格子
	return dp[goodsValues.size() - 1][capacity - 1];
}

int Solution::getDpValue(const vector<vector<int>> dp, int goodsValue, int capacity)
{
	if (goodsValue < 0 || capacity < 0)
		return 0;

	return dp[goodsValue][capacity];
}
