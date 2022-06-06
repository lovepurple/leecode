#include <iostream>
#include <vector>

using namespace std;

/*
	��Ŀ��ʵ�һ�γ��ֵ�����������һֱҪ�ƽ���left == right leftҪ��rightһֱ�ƽ�
	��һ�γ��ֿ��ܲ��ǵ�һ�γ���
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
		if (nums[mid] >= target)			//���������Ϊ���ҵ�Ŀ�����ж��������£���������
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