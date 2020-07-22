#include <iostream>
#include <vector>
/*
	0-1背包问题  考虑的是和不装当前物品 带来的影响

	0-1 背包问题特点是每个物品只有一个。

	外层循环是物品列表，内层循环是容量大小
*/
using namespace std;

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
};


int main()
{
	return 0;
}

int Solution::zeroOneMaxValue(const vector<int> goodsValues, const vector<int> goodsWeights, const int capacity)
{
	//dp[i][j] 前i件商品，在j容量下的最大价值
	vector<vector<int>> dp(goodsValues.size() + 1);

	//外层循环控制装几个物品

	for (vector<int>::const_iterator itGoodsValue = goodsValues.begin(); itGoodsValue != goodsValues.end(); ++itGoodsValue)
	{
		int indexOfGoods = distance(itGoodsValue, goodsValues.begin());
		dp[indexOfGoods] = vector<int>(capacity + 1);

		int currentGoodsWeight = *itGoodsValue;

		for (int j = 1; j <= capacity; ++j)
		{


		}
	}


	//递推表最后一个格子
	return dp[goodsValues.size()][capacity];
}
