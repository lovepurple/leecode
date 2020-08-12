/**
 * dp 解斐波那契
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int fib(int n);

};

int main()
{
	Solution s;
	int n = 0;
	cout << s.fib(n);

	return 0;
}

int Solution::fib(int n)
{
	if (n == 0)
		return 0;

	vector<int> dp(n + 1);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; ++i)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;


	return dp[n];
}
