#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& src, int i, int j)
{
	int tmp = src[i];
	src[i] = src[j];
	src[j] = tmp;
}

void quickSort(vector<int>& src, int begin, int end)
{
	if (begin > end)
		return;

	int pivot = src[begin];
	int left = begin;
	int right = end;

	while (left < right)
	{
		while (left < right && src[right] >= pivot)
			right--;

		while (left < right && src[left] <= pivot)
			left++;

		if (left < right)
			swap(src, left, right);
	}

	if (pivot > src[left])
		swap(src, begin, left);

	quickSort(src, begin, left - 1);
	quickSort(src, left + 1, end);
}

void nextPermutation(vector<int>& nums)
{
	//两边扫描 第一遍确定从哪位开始是大的那位，
   //第二遍找到比确定位大的数，交换
   //反转交换点之后的 从小到大排列
	if (nums.size() <= 1)
		return;

	int i = nums.size() - 2;
	while (i >= 0 && nums[i + 1] <= nums[i])
		i--;

	if (i >= 0)
	{
		int j = nums.size() - 1;
		while (nums[j] <= nums[i])
			j--;

		if (j > i)
			swap(nums, i, j);
	}

	reverse(nums.begin() + (i + 1), nums.end());

}

int main()
{
	vector<int> nums = { 1,2,1 };
	nextPermutation(nums);

	cout << nums.size();

	return 0;
}