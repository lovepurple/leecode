#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;

	int sumOfWindow = nums[0];
	int windowLeft = 0;
	int windowRight = 0;

	int minLength = INT_MAX;

	while (windowLeft < nums.size())
	{

		if (sumOfWindow >= target)
		{
			minLength = min(minLength, windowRight - windowLeft + 1);

			sumOfWindow -= nums[windowLeft];
			windowLeft++;
		}
		else
		{
			if (windowRight < nums.size() - 1)
			{
				windowRight++;
				sumOfWindow += nums[windowRight];
			}
			else
			{
				sumOfWindow -= nums[windowLeft];
				windowLeft++;
			}
		}
	}

	return  minLength == INT_MAX ? 0 : minLength;

}

int main()
{
	vector<int> nums = { 1,1,1,1,1,1,1,1 };
	int target = 11;

	cout << minSubArrayLen(target, nums);
	return 0;
}