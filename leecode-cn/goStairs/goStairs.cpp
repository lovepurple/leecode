/*
	递归+DP 上楼梯问题

	https://leetcode-cn.com/problems/three-steps-problem-lcci/
*/
#include <iostream>

class Solution
{
public:
	int waysToStep(int n);
private:

	//std::unordered_map<long, int> m_cachMap;

};



int main()
{
	int totalStairs = 61;
	Solution solution;
	std::cout << solution.waysToStep(totalStairs);

	system("pause");
	return 0;
}

int Solution::waysToStep(int n)
{
	//todo:如果使用递归，会造成重复太多，使用缓存表
	if (n <= 0)
		return 0;

	//n=1 n=2 n=3 是最核心的解
	if (n == 1)
		return 1;

	if (n == 2)
		return 2;

	if (n == 3)
		return 4;

	//本地变量 代替递归
	int* dpTable = new int[n + 1];
	dpTable[0] = 0;
	dpTable[1] = 1;
	dpTable[2] = 2;
	dpTable[3] = 4;

	//反着考虑,反向可以确认出之前的已有
	for (int i = 4; i <= n; ++i)
	{
		//1000000007  是int32中最大的质数，mod 1000000007  可以保证值 永远在int内
		dpTable[i] = ((dpTable[i - 1] + dpTable[i - 2]) % 1000000007 + dpTable[i - 3]) % 1000000007;
		//dpTable[i] %= 1000000007;

	}



	return dpTable[n];
}
