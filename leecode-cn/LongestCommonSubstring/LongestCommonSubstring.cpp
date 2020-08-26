/*
	LCS 最长公共子序列
	"1A2C3D4B56","B1D23CA45B6A"
	123456  12C4B6
	找出两个string中最长的子序列，

	dp[i][j] 为每一个串前i 第二个串前j的公共子序列
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
	string LCS(string s1, string s2);
};

int main()
{
	Solution s;
	string s1 = "1A12C3D";
	string s2 = "C1A2D";

	cout << s.LCS(s1, s2);

	return 0;
}

string Solution::LCS(string s1, string s2)
{
	//dp[i][j] 为s1的前i个字符 ， s2的前j个字符的最长子序列 （DP。。。。。。。的意义要与条件有联系。）
	vector<vector<int>> dp(s1.size(), vector<int>(s2.size()));

	string strLCS = "";
	int maxLengthCommonString = INT_MIN;

	//初始化i=0的情况
	for (int i = 0; i < s1.size(); ++i)
	{
		char c1 = s1[i];
		char c2 = s2[0];

		if (i == 0)
			dp[i][0] = c1 == c2 ? 1 : 0;
		else
			dp[i][0] = dp[i - 1][0];
	}

	for (int j = 0; j < s2.size(); ++j)
		dp[0][j] = dp[0][0];

	if (dp[0][0] == 1)
	{
		strLCS += s1[0];
		maxLengthCommonString = 1;
	}

	for (int i = 1; i < s1.size(); ++i)
	{
		char c1 = s1[i];
		for (int j = 1; j < s2.size(); ++j)
		{
			char c2 = s2[j];

			if (c1 == c2)
			{
				dp[i][j] = dp[i - 1][j] + 1;
				strLCS += c1;

				maxLengthCommonString = max(maxLengthCommonString, dp[i][j]);

				//之后的都是跟当前一样
				while (++j < s2.size())
					dp[i][j] = dp[i][j - 1];

			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	if (maxLengthCommonString == 0)
		strLCS = "-1";

	return strLCS;
}
