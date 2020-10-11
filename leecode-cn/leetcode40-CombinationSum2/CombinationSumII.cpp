#include <iostream>
#include <vector>
#include <algorithm>
/**
 * 回溯法
 */

using namespace std;

class Solution
{
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target);

	void backTrace(vector<int>& candidates, int candidateIndex, int target, vector<int>& vecCurrentCombine, vector<vector<int>>& vecResult);

	bool addCombinationToResult(vector<int> vecCombination, vector<vector<int>>& vecResult);

	bool addCombinationToResult2(vector<int> vecCombination, vector<vector<int>>& vecResult);
};

int main()
{
	Solution s;
	vector<int> candidates = { 10,1,2,7,6,1,5 };
	
	int target = 8;

	vector<vector<int>> vecResult = s.combinationSum2(candidates, target);
	cout << vecResult.size();

	return 0;
}

vector<vector<int>> Solution::combinationSum2(vector<int>& candidates, int target)
{
	vector<vector<int>> vecResult = {};
	if (candidates.size() == 0)
		return vecResult;

	vector<int> vecCurrent = {};
	std::sort(candidates.begin(), candidates.end());

	backTrace(candidates, 0, target, vecCurrent, vecResult);

	return vecResult;
}

void Solution::backTrace(vector<int>& candidates, int candidateIndex, int target, vector<int>& vecCurrentCombine, vector<vector<int>>& vecResult)
{
	if (target == 0)
	{
		addCombinationToResult2(vecCurrentCombine, vecResult);
		return;
	}


	if (candidateIndex >= candidates.size())
		return;

	if (target < 0)
		return;

	for (int i = candidateIndex; i < candidates.size(); ++i)
	{
		int candidateElement = candidates[i];
		vecCurrentCombine.push_back(candidateElement);
		backTrace(candidates, i + 1, target - candidateElement, vecCurrentCombine, vecResult);
		vecCurrentCombine.pop_back();
	}
}

bool Solution::addCombinationToResult(vector<int> vecCombination, vector<vector<int>>& vecResult)
{
	std::sort(vecCombination.begin(), vecCombination.end());

	bool isExistResult = false;
	for (vector<int> existResult : vecResult)
	{
		if (existResult.size() == vecCombination.size())
		{
			isExistResult = true;
			for (int i = 0; i < existResult.size(); ++i)
				isExistResult = isExistResult && existResult[i] == vecCombination[i];

			if (isExistResult)
				break;
		}
	}

	if (!isExistResult)
	{
		vector<int>* pResult = new vector<int>();
		for (int combinationElement : vecCombination)
			pResult->push_back(combinationElement);

		vecResult.push_back(*pResult);
	}

	return !isExistResult;
}

bool Solution::addCombinationToResult2(vector<int> vecCombination, vector<vector<int>>& vecResult)
{
	bool isExistResult = false;
	for (vector<int> existResult : vecResult)
	{
		if (existResult.size() == vecCombination.size())
		{
			isExistResult = true;
			for (int i = 0; i < existResult.size(); ++i)
				isExistResult = isExistResult && existResult[i] == vecCombination[i];

			if (isExistResult)
				break;
		}
	}

	if (!isExistResult)
	{
		vector<int>* pResult = new vector<int>();
		for (int combinationElement : vecCombination)
			pResult->push_back(combinationElement);

		vecResult.push_back(*pResult);
	}

	return !isExistResult;
}
