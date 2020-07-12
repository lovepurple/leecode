#include <iostream>
#include <vector>

/*
https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
	输入数据是有序的，所以使用对撞指针
*/
using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int>& numbers, int target);
};

vector<int> Solution::twoSum(vector<int>& numbers, int target)
{
	vector<int> vecResult;
	int index1 = 0;
	int index2 = numbers.size() - 1;

	while (index1 < index2)
	{
		int sumResult = numbers[index1] + numbers[index2];
		if (sumResult == target)
		{
			vecResult.push_back(index1 + 1);
			vecResult.push_back(index2 + 1);

			return vecResult;
		}
		else if (sumResult < target)
			index1++;
		else
			index2--;
	}

	return vecResult;
}

int main()
{
	Solution s;
	vector<int> inputNumber = { 2,7,11,15 };
	int target = 9;

	vector<int> sumResult = s.twoSum(inputNumber, target);

	return 0;
}