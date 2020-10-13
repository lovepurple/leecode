#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int integerBreak(int n);
};

int main()
{
	Solution s;
	int n = 8;

	int breakMultiply = s.integerBreak(n);

	cout << breakMultiply;

	return 0;
}

int Solution::integerBreak(int n)
{
	if (n == 2)
		return 1;

	if (n == 3)
		return 2;

	//找规律

	//离线值 ，2 3是特殊值。
	vector<int> dp(n + 1);
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 4;

	for (int i = 5; i <= n; ++i)
	{
		////偶数
		//if (i % 2 == 0)
		//	dp[i] = dp[i / 2] * dp[i / 2];
		//else
		//{
		//	//3的倍数
		//	if (i % 3 == 0)
		//	{
		//		dp[i] = 3 * dp[i - 3];
		//	}
		//	else
		//	{
		//		dp[i] = dp[i / 2] * dp[(i + 1) / 2];
		//	}
		//}

		dp[i] = 3 * dp[i - 3];
	}

	return dp[n];
}
