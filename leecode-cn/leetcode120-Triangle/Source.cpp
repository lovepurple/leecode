#include <iostream>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle)
{
	if (triangle.size() == 1)
		return triangle[0][0];

	int* dp = new int[triangle.size()];
	int minTotal = INT_MAX;
	dp[0] = triangle[0][0];

	for (int i = 1; i < triangle.size(); ++i)
	{
		vector<int> row = triangle[i];
		vector<int> previousRow = triangle[i - 1];
		minTotal = INT_MAX;

		//技巧，反向遍历，防止dp[i]被改写
		for (int j = row.size() - 1; j >= 0; --j)
		{
			int element = row[j];

			if (j == 0)
				dp[j] = element + dp[j];
			else if (j < row.size() - 1)
				dp[j] = element + min(dp[j], dp[j - 1]);
			else
				dp[j] = element + dp[j - 1];

			minTotal = min(minTotal, dp[j]);
		}
	}

	return minTotal;
}

int main()
{
	vector<vector<int>> input = { {2},{3,4},{6,5,7},{4,1,8,3} };

	int minimunTotal = minimumTotal(input);
	cout << minimunTotal;
	return 0;
}