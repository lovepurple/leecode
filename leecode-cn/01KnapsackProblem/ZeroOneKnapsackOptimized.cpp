#include "ZeroOneKnapsackOptimized.h"
#include <algorithm>

/// <summary>
/// 一维数组优化版的01背包
/// </summary>
/// <param name="goodsValues"></param>
/// <param name="goodsWeights"></param>
/// <param name="totalCapacity"></param>
/// <returns></returns>
int ZeroOneKnapsackOptimized::ZeroOneKnapsack(const std::vector<int> goodsValues, const std::vector<int> goodsWeights, int totalCapacity)
{
	std::vector<int> dp(totalCapacity + 1);

	//初始化i=0 是的dp[j] 只有一个物品时
	int weightOfW0 = goodsWeights[0];
	for (int j = 0; j <= totalCapacity; ++j)
		dp[j] = j >= weightOfW0 ? goodsValues[0] : 0;


	for (int i = 1; i < goodsValues.size(); ++i)
	{
		int weightOfGoods = goodsWeights[i];
		//反向计算
		for (int j = totalCapacity; j >= 0; --j)
		{
			if (j >= weightOfGoods)
				dp[j] = std::max(dp[j], dp[j - weightOfGoods] + goodsValues[i]);
		}
	}

	return dp[totalCapacity];
}
