#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int rob(vector<int>& nums);
};

int main()
{
	Solution s;
	vector<int> room = { 2,7,9,3,1 };

	cout << s.rob(room);

	return 0;
}

int Solution::rob(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;

	if (nums.size() == 1)
		return nums[0];

	vector<int> dp(nums.size() + 1);			//dp多分配一个

	dp[0] = 0;
	dp[1] = nums[0];

	for (int i = 2; i <= nums.size(); ++i)
		dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);

	return dp[nums.size()];
}
