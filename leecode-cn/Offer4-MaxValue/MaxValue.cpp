#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int maxValue(vector<vector<int>>& grid);
};

int main()
{
	Solution s;
	vector<vector<int>> vecGrid = { {1,3,1},{1,5,1},{4,2,1} };
	int maxValue = s.maxValue(vecGrid);
	cout << maxValue;
	return 0;
}

int Solution::maxValue(vector<vector<int>>& grid)
{
	if (grid.size() == 0)
		return 0;

	vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1));


	for (int i = 1; i <= grid.size(); ++i)
	{
		for (int j = 1; j <= grid[0].size(); ++j)
		{
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + grid[i - 1][j - 1];
		}

	}

	return dp[grid.size()][grid[0].size()];
}
