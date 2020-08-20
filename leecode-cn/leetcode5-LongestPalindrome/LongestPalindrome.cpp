/*
	最长回文串

	dp[i][j] 为 i-j 之间是否是回文串
	状态转移方程	dp[i][j] = dp[i+1][j-1] && s[i]==s[j]
	dp[i][j] 需要用到 左下的，所以填表要按列填
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	string longestPalindrome(string s);
};

int main()
{
	Solution s;
	string str = "cbbd";

	cout << s.longestPalindrome(str) << endl;

	return 0;
}

string Solution::longestPalindrome(string s)
{
	//一个字母
	if (s.length() == 1)
		return s;

	//定义dp[i][j]，是否s[i:j] 是回文串
	vector<vector<bool>> dp(s.length() + 1, vector<bool>(s.length() + 1));
	int longestPalidromeStart = 0;
	int longestPalidromeEnd = -1;

	//按列填充dp
	for (int j = 1; j <= s.length(); ++j)
	{
		for (int i = 0; i <= s.length(); ++i)
		{
			if (j < i)			//j不可能小于i
				break;
			else if (i == j)		//单个字母true			
				dp[i][j] = true;
			else
			{
				//如果 i+1<j-1 说明是两个字母（对角线以下。）j-1 < i+1 时直接true
				if (i + 1 > j - 1)
					dp[i + 1][j - 1] = true;

				dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];


				//最长的序列 起始index
				if (dp[i][j] && j - i > longestPalidromeEnd - longestPalidromeStart)
				{
					longestPalidromeStart = i;
					longestPalidromeEnd = j;
				}
			}
		}
	}

	if (longestPalidromeEnd - longestPalidromeStart <= 0)
		return "";

	return s.substr(longestPalidromeStart, longestPalidromeEnd - longestPalidromeStart + 1);
}
