/*
	https://www.nowcoder.com/practice/e016ad9b7f0b45048c58a9f27ba618bf?tpId=188&&tqId=35164&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking
	有一个整数数组，请你根据快速排序的思路，找出数组中第K大的数。

给定一个整数数组a,同时给定它的大小n和要找的K(K在1到n之间)，请返回第K大的数，保证答案存在。

*/
#include <iostream>
#include <vector>

using namespace std;

class Finder
{
public:
	int findKth(vector<int> a, int n, int k);

	int qSort(vector<int>& nums, int indexFrom, int indexTo);

	int qSortWithKth(vector<int>& nums, int indexFrom, int indexTo, int k);

	void swap(vector<int>& nums, int index0, int index1);
};

int main()
{
	Finder f;
	vector<int> nums = { 1332802,1177178,1514891,871248,753214,123866,1615405,328656,1540395,968891,1884022,252932,1034406,1455178,821713,486232,860175,1896237,852300,566715,1285209,1845742,883142,259266,520911,1844960,218188,1528217,332380,261485,1111670,16920,1249664,1199799,1959818,1546744,1904944,51047,1176397,190970,48715,349690,673887,1648782,1010556,1165786,937247,986578,798663 };

	vector<int> nums2 = { 1332802,1177178,1514891,871248,753214,123866,1615405,328656,1540395,968891,1884022,252932,1034406,1455178,821713,486232,860175,1896237,852300,566715,1285209,1845742,883142,259266,520911,1844960,218188,1528217,332380,261485,1111670,16920,1249664,1199799,1959818,1546744,1904944,51047,1176397,190970,48715,349690,673887,1648782,1010556,1165786,937247,986578,798663
	};
	int k = 24;
	//cout << f.findKth(nums, nums.size(), k);
	//cout << f.qSort(nums2, 0, nums2.size() - 1);

	cout << f.qSortWithKth(nums2, 0, nums2.size() - 1, k - 1);

	return 0;
}

int Finder::findKth(vector<int> a, int n, int k)
{
	/*
		基础版
	int index = qSort(a, 0, a.size() - 1);
	return a[3];*/

	//优化版
	int kth = qSortWithKth(a, 0, n - 1, k);

	return a[k];
}
/// <summary>
/// 第一版以qsort为主，优化版 qsort(from,index 只需要保证 from<=k <= index)就行 每次少一半的计算
/// </summary>
/// <param name="nums"></param>
/// <param name="indexFrom"></param>
/// <param name="indexTo"></param>
/// <returns></returns>
int Finder::qSort(vector<int>& nums, int indexFrom, int indexTo)
{
	if (indexFrom >= indexTo)
		return indexFrom;

	int pivot = nums[indexFrom];
	int indexLeft = indexFrom + 1;
	int indexRight = indexTo;

	while (indexLeft < indexRight)
	{
		while (nums[indexRight] > pivot && indexRight > indexLeft)
			indexRight--;

		while (nums[indexLeft] < pivot && indexRight > indexLeft)
			indexLeft++;

		if (indexLeft < indexRight)			//交换后不需要indexleft++ right-- 
			swap(nums, indexLeft, indexRight);
	}

	int pivotIndex = indexLeft;
	if (pivot > nums[indexLeft])
		swap(nums, indexFrom, indexLeft);
	else
		pivotIndex = indexFrom;

	qSort(nums, indexFrom, pivotIndex - 1);
	qSort(nums, pivotIndex + 1, indexTo);

	return indexFrom;
}

int Finder::qSortWithKth(vector<int>& nums, int indexFrom, int indexTo, int k)
{
	if (indexFrom >= indexTo)
		return indexFrom;

	int pivot = nums[indexFrom];
	int indexLeft = indexFrom + 1;
	int indexRight = indexTo;

	while (indexLeft < indexRight)
	{
		while (nums[indexRight] < pivot && indexRight > indexLeft)
			indexRight--;

		while (nums[indexLeft] > pivot && indexRight > indexLeft)
			indexLeft++;

		if (indexLeft < indexRight)
			swap(nums, indexLeft, indexRight);

	}

	int pivotIndex = indexLeft;
	if (pivot < nums[indexLeft])
		swap(nums, indexFrom, indexLeft);
	else
		pivotIndex = indexFrom;

	if (pivotIndex == k)
		return nums[k];
	else if (k < pivotIndex)
		return qSortWithKth(nums, indexFrom, pivotIndex - 1, k);
	else
		return qSortWithKth(nums, pivotIndex + 1, indexTo, k);
}

//nums是参数，非拷贝 在函数内部改变无效
void Finder::swap(vector<int>& nums, int index0, int index1)
{
	int temp = nums[index0];
	nums[index0] = nums[index1];
	nums[index1] = temp;
}
