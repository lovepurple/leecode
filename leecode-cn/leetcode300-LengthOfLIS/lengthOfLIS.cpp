/*
	最长上升子序列 DP
	dp[i] 前i个数据组成的最大上升子序列


*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int lengthOfLIS(vector<int>& nums);
};

int main()
{
	Solution s;
	vector<int> num = { 10,9,2,5,3,7,101,18 };
	cout << s.lengthOfLIS(num) << endl;

	return 0;
}

int Solution::lengthOfLIS(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;

	vector<int> dp(nums.size());



	for (int i = 0; i < nums.size(); ++i)
	{
		int currentNum = nums[i];
		dp[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if (currentNum > nums[j])
			{
				//todo!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				/*
					dp[i] 为前 i 个数时 最大的连续序列
						更新规则： 每一个i 对i 前面的所有元素进行枚举
						dp[j] 为不包括i 时的最大数

				*/
				dp[i] = max(dp[i], dp[j] + 1);

			}
		}
	}

	int max = INT_MIN;
	for (int i = 0; i < dp.size(); ++i)
		max = dp[i] > max ? dp[i] : max;


	return max;
}
