/*
	https://leetcode-cn.com/problems/partition-equal-subset-sum/
	分割等和子集，0-1 背包的变种

	求一个结果值
	本题技巧是分成两个子集相等的，那么原始数 / 2 为dp的遍历条件
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	bool canPartition(vector<int>& nums);
};

int main()
{
	vector<int> nums = { 1,5,11,7 };
	Solution s;
	cout << s.canPartition(nums);

	return 0;
}

bool Solution::canPartition(vector<int>& nums)
{
	int sumOfNums = 0;

	for (int num : nums)		//C++ 的便利简写
		sumOfNums += num;

	//奇数 一定不能分成两个相等的
	if (sumOfNums % 2 != 0)
		return false;

	int subArrayTarget = sumOfNums / 2;

	/*
		dp[i][j] 为前i个数量是否能组成和为j
		状态转移方程：
			如果 dp[i-1][j] = target  =>  dp[i][j] = dp[i-1][j] （不用选当前数就可以组成结果）
	*/
	vector<vector<bool>> dp(nums.size());
	dp[0] = vector<bool>(subArrayTarget + 1);
	dp[0][0] = true;
	for (int j = 1; j <= subArrayTarget; ++j)
		dp[0][j] = nums[0] == j;


	for (int i = 1; i < nums.size(); ++i)
	{
		dp[i] = vector<bool>(subArrayTarget + 1);
		dp[i][0] = true;

		for (int j = 1; j <= subArrayTarget; ++j)
		{
			//不选当前的数就能组成目标
			if (dp[i - 1][j])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = j - nums[i] > 0 ? dp[i - 1][j - nums[i]] : false;			//前i-1个能组成j-num[j] => i 个能组成 j-num[j] + num[j] 
		}
	}


	return dp[nums.size() - 1][subArrayTarget];
}
