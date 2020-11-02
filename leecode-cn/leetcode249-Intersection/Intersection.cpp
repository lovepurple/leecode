#include <iostream>
#include<vector>
#include <unordered_set>

using namespace std;
class Solution
{
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2);

	vector<int> intersectionOptimize(vector<int>& num1, vector<int>& num2);

private:
	void qSort(vector<int>& num, int indexBegin, int indexEnd);
};

int main()
{
	Solution s;

	vector<int> nums1 = { 1,2 };
	vector<int> nums2 = { 1,1 };

	//vector<int> vecIntersection = s.intersection(nums1, nums2);
	vector<int> vecIntersection = s.intersectionOptimize(nums1, nums2);

	cout << vecIntersection.size();

	return 0;
}

vector<int> Solution::intersection(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> vecIntersection;
	if (nums1.size() == 0 || nums2.size() == 0)
		return vecIntersection;

	unordered_set<int> intersectionSet;
	unordered_set<int> uniqueSet;
	for (int num1 : nums1)
		uniqueSet.insert(num1);

	for (int num2 : nums2)
	{
		if (uniqueSet.find(num2) != uniqueSet.end())
			intersectionSet.insert(num2);
	}

	for (int val : intersectionSet)
		vecIntersection.push_back(val);

	return vecIntersection;
}

vector<int> Solution::intersectionOptimize(vector<int>& nums1, vector<int>& nums2)
{
	//由于已经排序好，可使用最后一个元素判断存不存在
	vector<int> vecIntersection;
	if (nums1.size() == 0 || nums2.size() == 0)
		return vecIntersection;

	qSort(nums1, 0, nums1.size() - 1);
	qSort(nums2, 0, nums2.size() - 1);

	int index0 = 0;
	int index1 = 0;

	while (index0 < nums1.size() && index1 < nums2.size())
	{
		if (nums1[index0] < nums2[index1])
			index0++;
		else if (nums1[index0] > nums2[index1])
			index1++;
		else/* (nums1[index0] == nums2[index1])*/
		{
			if (vecIntersection.empty() || vecIntersection.back() != nums1[index0])
				vecIntersection.push_back(nums1[index0]);

			index0++;
			index1++;
		}
	}

	return vecIntersection;
}


void Solution::qSort(vector<int>& num, int indexBegin, int indexEnd)
{
	if (indexBegin > indexEnd)
		return;

	int pivot = num[indexBegin];
	int left = indexBegin;
	int right = indexEnd;

	while (left < right)
	{
		while (num[right] >= pivot && left < right)
			right--;

		while (num[left] <= pivot && left < right)
			left++;

		if (left < right)
		{
			int temp = num[left];
			num[left] = num[right];
			num[right] = temp;
		}
	}

	if (pivot > num[left])
	{
		int temp = num[indexBegin];
		num[indexBegin] = num[left];
		num[left] = temp;
	}

	qSort(num, indexBegin, left - 1);
	qSort(num, left + 1, indexEnd);
}