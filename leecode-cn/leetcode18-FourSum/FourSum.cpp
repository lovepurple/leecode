#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	递归+回溯
*/
class Solution
{
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target);

private:
	void backTrace(vector<int> nums, int numIndex, int target, vector<int>& currentCombination, vector<vector<int>>& vecResult);

	void addToResult(vector<int> vecCombination, vector<vector<int>>& vecResult, const vector<int> nums);

};


int main()
{
	Solution s;
	vector<int> nums = { -493, -482, -482, -456, -427, -405, -392, -385, -351, -269, -259, -251, -235, -235, -202, -201, -194, -189, -187, -186, -180, -177, -175, -156, -150, -147, -140, -122, -112, -112, -105, -98, -49, -38, -35, -34, -18, 20, 52, 53, 57, 76, 124, 126, 128, 132, 142, 147, 157, 180, 207, 227, 274, 296, 311, 334, 336, 337, 339, 349, 354, 363, 372, 378, 383, 413, 431, 471, 474, 481, 492
	};

	int target = 6189;
	vector<vector<int>> result = s.fourSum(nums, target);

	cout << result.size();

	return 0;
}

vector<vector<int>> Solution::fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> vecResult;
	if (nums.size() == 0)
		return vecResult;

	vector<int> vecCombinationIndex;
	std::sort(nums.begin(), nums.end());

	backTrace(nums, 0, target, vecCombinationIndex, vecResult);

	return vecResult;
}

void Solution::backTrace(vector<int> nums, int numIndex, int target, vector<int>& currentCombinationIndex, vector<vector<int>>& vecResult)
{
	if (currentCombinationIndex.size() >= 4)
	{
		if (target == 0)
			addToResult(currentCombinationIndex, vecResult, nums);

		return;
	}

	if (numIndex >= nums.size())
		return;

	for (int i = numIndex; i < nums.size(); ++i)
	{
		if (std::find(currentCombinationIndex.begin(), currentCombinationIndex.end(), i) == currentCombinationIndex.end())
		{
			currentCombinationIndex.push_back(i);

			backTrace(nums, i + 1, target - nums[i], currentCombinationIndex, vecResult);

			currentCombinationIndex.pop_back();

			//由于是排好序的，后面的要比现在的大 也可以return 
			if (currentCombinationIndex.size() == 3 && nums[i] >= target)
				break;
		}
	}
}

void Solution::addToResult(vector<int> vecCombination, vector<vector<int>>& vecResult, const vector<int> nums)
{
	//sort(vecCombination.begin(), vecCombination.end());

	bool isExist = false;
	for (vector<int> vecAlreadyExist : vecResult)
	{
		//去重技巧，由于都是排序好的，只判断第一个可去掉大量判断
		int index = 0;
		if (vecAlreadyExist[0] != nums[vecCombination[0]])
			continue;

		for (int i = 1; i < vecCombination.size()-1; ++i)
		{
			if (vecAlreadyExist[i] != nums[vecCombination[i]])
				break;

			if (i == vecCombination.size() - 2)
				isExist = true;
		}
	}

	if (!isExist)
	{
		vector<int>* pCombination = new vector<int>();
		for (int combinationElementIndex : vecCombination)
			pCombination->push_back(nums[combinationElementIndex]);

		vecResult.push_back(*pCombination);
	}

}
