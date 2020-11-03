#include <iostream>
#include <vector>
/*
	今天，书店老板有一家店打算试营业 customers.length分钟，每分钟都有一些顾客customers[i] 会进入书店，的呢这些顾客都会在那一分钟结束后离开。
	在某些时候，书店老板会生气。如果书店老板在第i分钟生气，那么grumpy[i] = 0 当书店老板生气时，那一分钟的顾客就会不满意，不生气就是满意的。

	书店老板知道一个秘密技巧，能抑制自己的情绪，可以让自己连续X分钟不生气，但却只能使用一次，

	请返回这一天营业下来 最多有多少客户能够感到满意的数量

	输入： customers = [1,0,1,2,1,1,7,5]
		 grumpy =     [0,1,0,1,0,1,0,1]
		 X = 3
	输出：  16
		书店老板在最后3分钟保持冷静
			1+1+1+1+1+7+5 = 16
			https://leetcode-cn.com/problems/grumpy-bookstore-owner/solution/onfu-za-du-dong-tai-gui-hua-by-jiachen_zhang/

	使用 滑动窗口
*/

using namespace std;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X)
{
	if (customers.size() != grumpy.size())
		return 0;

	vector<vector<int>> dp(customers.size() + 1, vector<int>(customers.size() + 1));
	dp[0][0] = customers[0];
	dp[1][0] = customers[0] + customers[1];


	for (int i = 1; i <= customers.size(); ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (j < X)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				int max = 0;


			}


		}

	}


}

int maxSatisfiedSlidingWindow(vector<int>& customers, vector<int>& grumpy, int X)
{
	int indexLeft = 0;
	int indexRight = 0;

	//滑动窗口最大值
	int windowMax = 0;

	int normalVal = 0;			//不使用技能的时候的正常值
	int windowTemp = 0;

	while (indexRight < customers.size())
	{
		//滑动右面 记录不使用技能时的值 
		normalVal += grumpy[indexRight] == 0 ? customers[indexRight] : 0;

		//使用技能时，能扭转回的值（窗口内）
		if (grumpy[indexRight] == 1)
			windowTemp += customers[indexRight];

		indexRight++;

		//left ~ right 超出窗口x，left++ 缩小窗口  ,等号的问题  right - left >=x ， 窗口大小是包括边界， 
		if (indexRight - 1 - indexLeft >= X)
		{
			//被技能扭转的
			if (grumpy[indexLeft] == 1)
				windowTemp -= customers[indexLeft];

			indexLeft++;
		}

		//找出所有窗口最大技能值（在技能下 额外附加的值 ）
		windowMax = max(windowMax, windowTemp);
	}

	//最终结果 = 正常的影响下 + 最大技能窗口的附加值
	return normalVal + windowMax;
}

int main()
{
	vector<int> vecCustomers = { 2,6,6,9 };
	vector<int> vecGrumpy = { 0,0,1,1 };
	int x = 1;

	cout << maxSatisfiedSlidingWindow(vecCustomers, vecGrumpy, x);

	return 0;
}