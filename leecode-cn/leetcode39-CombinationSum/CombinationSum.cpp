#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target);

	void backTrace(const vector<int> candidates, int target, vector<int>& currentCombination, vector<vector<int>>& vecResult);

	bool addCombinationToResult2(vector<int> vecCombination, vector<vector<int>>& vecResult);
};


int main()
{
	Solution s;
	vector<int> vecCandidates = { 2,3,5 };
	int target = 8;
	vector<vector<int>> candidateResult = s.combinationSum(vecCandidates, target);

	cout << candidateResult.size();
	return 0;
}

vector<vector<int>>  Solution::combinationSum(vector<int>& candidates, int target)
{
	vector<vector<int>> vecCombinationResult;
	vector<int> vecCurrentCombination;
	sort(candidates.begin(), candidates.end());

	backTrace(candidates, target, vecCurrentCombination, vecCombinationResult);

	return vecCombinationResult;
}

void Solution::backTrace(const vector<int> candidates, int target, vector<int>& currentCombination, vector<vector<int>>& vecResult)
{
	if (target == 0)
	{
		addCombinationToResult2(currentCombination, vecResult);
		return;
	}

	if (target < 0)
		return;

	for (int i = 0; i < candidates.size(); ++i)
	{
		int candidateElement = candidates[i];
		currentCombination.push_back(candidateElement);
		backTrace(candidates, target - candidateElement, currentCombination, vecResult);
		currentCombination.pop_back();
	}
}


bool Solution::addCombinationToResult2(vector<int> vecCombination, vector<vector<int>>& vecResult)
{
	bool isExistResult = false;
	sort(vecCombination.begin(), vecCombination.end());
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