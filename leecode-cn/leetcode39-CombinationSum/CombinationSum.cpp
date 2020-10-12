#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target);

	void backTrace(vector<int>& candidates, int target, vector<int>& currentCombination, vector<vector<int>>& vecResult);

	bool addCombinationToResult2(vector<int> vecCombination, vector<vector<int>>& vecResult);
};


int main()
{
	Solution s;
	vector<int> vecCandidates = { 2,3,6,7 };
	int target = 9;

	return 0;
}

bool Solution::combinationSum(vector<int>& candidates, int target)
{

}

void Solution::backTrace(vector<int>& candidates, int target, vector<int>& currentCombination, vector<vector<int>>& vecResult)
{

}