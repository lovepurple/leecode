#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
	假设你分别支配着 m 个 0 和 n 个 1。另外，还有一个仅包含 0 和 1 字符串的数组。
	你的任务是使用给定的 m 个 0 和 n 个 1 ，找到能拼出存在于数组中的字符串的最大数量。每个 0 和 1 至多被使用一次。

	输入: strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
	输出: 4
	解释: 总共 4 个字符串可以通过 5 个 0 和 3 个 1 拼出，即 "10","0001","1","0" 。

	本质是0-1背包的问题
		dp[i][j][k] 为	前i个目标字符串中
				使用j个0  k个1 拼出目标数组最大的数量

		状态转移方程：
			dp[i][j][k] = dp[i-1][j][k]												当前的j,k对结果没影响 和之前一样
						  dp[i-1][j-当前字符串中0的数量][k-当前字符串中1的数量] +1		选择当前的，结果为  不包含当前的数量 + 1 （0-1背包的变形）


		optimize:
			只和i-1有关 所以可优化空间到dp[i][j]二维 使用上一次就行

*/

class Solution
{
public:
	int FindMaxForm(vector<string>& strs, int m, int n);

	/*
		优化空间 使用二维代替三维dp ，
	*/
	int FindMaxFormOptimize1(vector<string>& strs, int m, int n);

	/*
		进一步优化循环，
	*/
	int FindMaxFormOptimize2(vector<string>& strs, int m, int n);

	pair<int, int> GetStrZeroOneCount(string strs, pair<int, int>& pairResult);
};

int main()
{
	vector<string> strs = { "10","0001","111001","1","0" };
	int m = 5;
	int n = 3;

	Solution s;
	int maxForm = s.FindMaxFormOptimize2(strs, m, n);

	cout << maxForm;

	return 0;
}

int Solution::FindMaxForm(vector<string>& strs, int m, int n)
{
	//dp[i][j][k]
	vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
	pair<int, int> strZeroOneInfo;

	for (int i = 1; i <= strs.size(); ++i)
	{
		string str = strs[i - 1];
		strZeroOneInfo = GetStrZeroOneCount(str, strZeroOneInfo);

		for (int j = 0; j <= m; ++j)
		{
			for (int k = 0; k <= n; ++k)
			{
				//当前m个0 n个1 已经超过目标字符串
				if (strZeroOneInfo.first <= j && strZeroOneInfo.second <= k)
				{
					dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - strZeroOneInfo.first][k - strZeroOneInfo.second] + 1);
				}
				else
					dp[i][j][k] = dp[i - 1][j][k];
			}
		}
	}

	return dp[strs.size()][m][n];
}

int Solution::FindMaxFormOptimize1(vector<string>& strs, int m, int n)
{
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));

	for (string str : strs)
	{
		pair<int, int> strZeroOneInfo;
		strZeroOneInfo = GetStrZeroOneCount(str, strZeroOneInfo);

		for (int i = m; i >= 0; --i)
		{
			for (int j = n; j >= 0; --j)
			{
				//由于原始dp都是0，可以将此步的判断和上面两层for循环合并，优化版见FindMaxFormOptimize2
				//相比FindMaxForm原始的三维状态转移方程，该方法在Leetcode上 时间由588ms-> 288ms  ，空间复杂度：100.3M -> 9.7M 非常大的优化
				if (i >= strZeroOneInfo.first && j >= strZeroOneInfo.second)
				{
					dp[i][j] = max(dp[i][j], dp[i - strZeroOneInfo.first][j - strZeroOneInfo.second] + 1);
				}
			}
		}
	}


	return dp[m][n];
}

int Solution::FindMaxFormOptimize2(vector<string>& strs, int m, int n)
{
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));

	for (string str : strs)
	{
		pair<int, int> strZeroOneInfo;
		strZeroOneInfo = GetStrZeroOneCount(str, strZeroOneInfo);

		//0或1的数量小于 当前目标串的 不需要计算，
		for (int i = m; i >= strZeroOneInfo.first; --i)
		{
			for (int j = n; j >= strZeroOneInfo.second; --j)
			{
				dp[i][j] = max(dp[i][j], dp[i - strZeroOneInfo.first][j - strZeroOneInfo.second] + 1);
			}
		}
	}

	return dp[m][n];
}

pair<int, int> Solution::GetStrZeroOneCount(string strs, pair<int, int>& pairResult)
{
	int oneCount = 0;
	for (char c : strs)
	{
		if (c == '1')
			oneCount++;
	}

	pairResult.first = strs.size() - oneCount;
	pairResult.second = oneCount;

	return pairResult;
}
