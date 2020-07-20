/*
	有三种硬币，分别为2，5，7 ，每种都足够多， 买一本快需要27元，如何使用最少的硬币组合正好付清。

	1. 最大最小值问题，使用动态规划
	2. 状态，最后一步是  2，5，或7  那么前一步是  27-2 ,27-5,27-7


	状态转移方程：
		f(x) = 最少用多少枚硬币拼出x
		f(x) = min(f(x-2),f(x-5),f(x-7) + 1
		每次都是上一个min + 1
		!!!!!
			x 是钱数，不是硬币数 f[x] 才是硬币数
		边界问题：
			x - 2 < 0 直接返回Int.Max
*/

#include <iostream>
#include <vector>

using namespace std;

int getCoinCount(const vector<int> coinList, int total);

int main()
{
	vector<int> vecCoins = { 2,5,7 };
	int totalAmount = 27;

	cout << "最少需要：" << getCoinCount(vecCoins, totalAmount) << "枚硬币才能拼出：" << totalAmount << endl;

	return 0;
}

int getCoinCount(const vector<int> coinList, int total)
{
	int* dp = new int[total + 1];
	dp[0] = INT_MAX;

	for (int i = 1; i <= total; ++i)
	{

		int minCoins = INT_MAX;

		//获取每次的最小值
		for (vector<int>::const_iterator it = coinList.begin(); it != coinList.end(); ++it)
		{
			if (i - *it > 0)
			{
				minCoins = min(minCoins, dp[i - *it]);
			}
		}


	}

	return dp[total]; +

}
