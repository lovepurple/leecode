#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<double> twoSum(int n);
};

int main()
{
	int n = 2;
	Solution s;
	vector<double> probabilities = s.twoSum(n);
	cout << probabilities.size();

	return 0;
}

vector<double> Solution::twoSum(int n)
{
	vector<vector<double>> dp(n + 1, vector<double>((n + 1) * 6));

	for (int i = 1; i <= n + 1; ++i)
	{
		for (int j = 1 * i; j <= 6 * i; ++j)
		{
			dp[i][j] = 



		}


	}

	return vector<double>();
}
