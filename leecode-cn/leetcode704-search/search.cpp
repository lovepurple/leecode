/*
	https://leetcode-cn.com/problems/binary-search/
	二分查找
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	Solution();
	~Solution();

	int search(vector<int>& nums, int target);

private:

};

Solution::Solution()
{
}

Solution::~Solution()
{
}

int Solution::search(vector<int>& nums, int target)
{
	int start = 0;
	int end = nums.size() - 1;

	while (start < end)		//边界问题
	{
		int mid = start + (end - start) / 2;
		if (nums[mid] > target)
			end = mid - 1;
		else if (nums[mid] < target)
			start = mid + 1;
		else
			return mid;
	}

	return nums[start] == target ? end : -1;
}

int main()
{
	//vector<int> nums = { -1,0,3,5,9,12 };
	//int target = 12;
	vector<int> nums = { 2,5 };
	int target = 0;

	Solution solution;
	int targetIndex = solution.search(nums, target);

	cout << targetIndex;

	return 0;
}