#include <iostream>
#include <vector>

using namespace std;

/*
	找目标词第一次出现的索引，二分一直要逼近到left == right left要向right一直逼近
	第一次出现可能不是第一次出现
*/

int binarySearch(vector<int>& nums, int target)
{
	if (nums.size() == 0)
		return -1;

	if (nums[0] == target)
		return 0;

	int left = 0;
	int right = nums.size() - 1;

	while (left <= right)
	{
		if (left == right)
			return nums[left] == target ? left : -1;

		int mid = (left + right) / 2;
		if (nums[mid] >= target)			//这个等于是为了找到目标数有多个的情况下，继续二分
			right = mid;
		else
			left = mid + 1;
	}

	return -1;
}


int main()
{
	vector<int> tuple = { 1,4,4,5,7,7,8,9,9,10 };
	int target = 6;

	cout << binarySearch(tuple, target);

	return 0;
}