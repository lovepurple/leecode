/*
	划分为k个相等的子集

	本题和 416 划分成两具子集不同

*/
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
	bool canPartitionKSubsets(vector<int>& nums, int k);

	/// <summary>
	/// 快排
	/// </summary>
	/// <param name="nums"></param>
	/// <param name="indexFrom"></param>
	/// <param name="indexEnd"></param>
	void quickSort(vector<int>& nums, int indexFrom, int indexEnd);

};

int main()
{
	Solution s;
	vector<int> num = { 4,3,2,3,5,2,1 };
	int k = 4;
	//cout << s.canPartitionKSubsets(num, k);

	s.quickSort(num, 0, num.size() - 1);

	return 0;
}

bool Solution::canPartitionKSubsets(vector<int>& nums, int k)
{
	int sumOfNums = nums[0];
	for (int i = 1; i < nums.size(); ++i)
		sumOfNums += nums[i];

	if (sumOfNums % k != 0)
		return false;

	int sumOfSubset = sumOfNums / k;



	return false;
}

void Solution::quickSort(vector<int>& nums, int indexFrom, int indexEnd)
{
	if (indexEnd - indexFrom < 1)
		return;

	int pivot = nums[indexFrom];
	int i = indexFrom + 1;
	int j = indexEnd;

	while (i < j)
	{
		while (nums[j] > pivot && j > i)
			j--;

		while (nums[i] < pivot && i < j)
			i++;

		if (i != j)
		{
			int tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;

			j--;
			i++;
		}
	}

	if (pivot > nums[j])
	{
		int tmp = nums[indexFrom];
		nums[indexFrom] = nums[j];
		nums[j] = tmp;
	}

	quickSort(nums, indexFrom, j - 1);
	quickSort(nums, j + 1, indexEnd);
}
