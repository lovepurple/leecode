#pragma once
#include <vector>
/*

	dp[i][j] = max(dp[i-1][j],dp[i-1][j-W[i]]+V[i])

	使用一维数组代替二维 优化空间复杂度：

	设:dp[j] 为在j 重量下能装的最大价值
	for i <-  1 to N:


	初始化第一个物品
		i=0;
		if j>=w[0]
			dp[j] = v[0]
		else
			dp[j] = 0

	dp[j] = max(dp[j],dp[j- W[i]]+v[i])
	而
		j-W[i] < j 因此在计算新的dp[j] 时需要用到在(i-1)时的dp[j]
		如果
			j<- 1 to C 会把当前的dp[j]覆盖，
			优化空间后的内层循环为
			j <- C  to 1   --j
				这样能保证在计算dp[j]时用到的 dp[j-w[i]]的值 没被覆盖。

*/

class ZeroOneKnapsackOptimized
{
public:
	int ZeroOneKnapsack(const std::vector<int> goodsValues, const std::vector<int> goodsWeights, int totalCapacity);
};

