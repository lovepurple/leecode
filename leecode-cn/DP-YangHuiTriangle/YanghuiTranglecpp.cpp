#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> getRow(int rowIndex);
};

int main()
{
	Solution s;
	s.getRow(5);

	return 0;
}

vector<int> Solution::getRow(int rowIndex)
{

	vector<int> dp(rowIndex + 1);
	dp[0] = 1;
	for (int i = 1; i <= rowIndex; ++i)
	{
		//需要倒着填充，下一次的j 需要用到最初的 正向会把数据覆盖
		for (int j = i; j >= 1; --j)
		{
			dp[j] = dp[j] + dp[j - 1];
		}
	}


	return dp;
}
