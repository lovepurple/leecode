#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int lengthOfLongestSubstring(string s);

	/// <summary>
	/// 双指针求解
	/// </summary>
	/// <param name="s"></param>
	/// <returns></returns>
	int lengthOfLongestSubstringDoublePointer(string s);

	bool isContain(string str, int begin, int end, char c);
};

int main()
{
	Solution s;
	string inputStr = "abcabcbb";
	cout << s.lengthOfLongestSubstringDoublePointer(inputStr);

	return 0;
}

//在leetcode中 用下面的dp会超时  如果s特别长的情况下。
int Solution::lengthOfLongestSubstring(string s)
{
	if (s.length() <= 1)
		return s.length();


	vector<vector<bool>> dp(s.length() + 1, vector<bool>(s.length() + 1));

	int longestSubString = 1;

	for (int i = 0; i < s.length(); ++i)
	{
		dp[i][i] = true;
		for (int j = i + 1; j < s.length(); ++j)
		{
			dp[i][j] = dp[i][j - 1] && !isContain(s, i, j - 1, s[j]);

			//optimize 只要为false 后面都不用看了
			if (!dp[i][j])
				break;
			else
				longestSubString = max(longestSubString, j - i + 1);
		}
	}


	return longestSubString;
}

int Solution::lengthOfLongestSubstringDoublePointer(string s)
{
	if (s.length() <= 1)
		return s.length();

	unordered_map<char, int> charIndexMap;

	int pointerSlow = 0;
	int pointerFast = 0;

	int longestSubStringLength = -1;
	while (pointerFast < s.length())
	{
		unordered_map<char, int>::iterator existied = charIndexMap.find(s[pointerFast]);
		if (existied != charIndexMap.end())
		{
			int currentSubstringLength = pointerFast - pointerSlow;

			longestSubStringLength = max(currentSubstringLength, longestSubStringLength);

			if (existied->second > pointerSlow)
				pointerSlow = pointerFast;
		}

		charIndexMap[s[pointerFast]] = pointerFast;

		pointerFast++;
	}

	longestSubStringLength = max(pointerFast - pointerSlow, longestSubStringLength);

	return longestSubStringLength;
}

bool Solution::isContain(string str, int begin, int end, char c)
{
	for (int i = begin; i <= end; ++i)
	{
		if (str[i] == c)
			return true;
	}

	return false;
}
