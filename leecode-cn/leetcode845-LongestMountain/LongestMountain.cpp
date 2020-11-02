#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int longestMountain(vector<int>& A);
};

int main()
{
	Solution s;
	vector<int> A = { 2,2,2 };
	int max = s.longestMountain(A);

	cout << max;
	return 0;
}

int Solution::longestMountain(vector<int>& A)
{
	vector<vector<int>> dp(A.size() + 1, vector<int>(A.size() + 1));
	int longestMountain = 0;

	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = i + 1; j < A.size(); ++j)
		{
			if (j == i + 1 && A[i] >= A[j])
				break;

			if (A[j] > A[j - 1])
				dp[i][j] = dp[i][j - 1] + 1;
			else if (A[j] < A[j - 1])
			{
				dp[i][j] = dp[i][j - 1] + 1;
				longestMountain = max(longestMountain, dp[i][j]);
			}
		}
	}

	return longestMountain == 0 ? 0 : longestMountain + 1;
}
