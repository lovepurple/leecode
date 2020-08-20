/*
	使用dp 计算字符串中有多少个回文子串

	dp[i][j] 为从i到j 是否是回文子串
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution
{
public:
	int countSubstring(string s);
};

int main()
{
	Solution s;
	string str = "aaa";
	cout << s.countSubstring(str);

	return 0;
}

int Solution::countSubstring(string s)
{
	if (s.size() == 1)
		return 1;

	vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));

	int substringCount = 0;
	for (int j = 0; j < s.size(); ++j)
	{
		for (int i = 0; i < s.size(); ++i)
		{
			if (i > j)
				break;
			else if (i == j)
				dp[i][j] = true;
			else
			{
				if (j - i < 2)
					dp[i + 1][j - 1] = true;

				dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
			}

			if (dp[i][j])
				substringCount++;
		}

	}

	return substringCount;
}
