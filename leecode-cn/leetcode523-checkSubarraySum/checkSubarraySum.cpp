/*
	连续的子数组和
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	bool checkSubarraySum(vector<int>& nums, int k);
};

int main()
{
	Solution s;
	vector<int> vec = { 0,1,0 };
	int k = 0;
	cout << s.checkSubarraySum(vec, k);

	return 0;

}

bool Solution::checkSubarraySum(vector<int>& nums, int k)
{

	vector<bool> dp(nums.size());

	for (int i = 1; i < nums.size(); ++i)
	{
		int sum = nums[i];
		for (int j = i - 1; j >= 0; --j)		//要连续的 需要向前找
		{
			sum += nums[j];
			if (k == 0)
				dp[i] = sum == k;
			else
				dp[i] = sum % k == 0;

			if (dp[i])
				return true;
		}
	}
	return false;
}
