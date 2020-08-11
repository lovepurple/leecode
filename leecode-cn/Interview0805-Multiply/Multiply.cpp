/*
	递归乘法。 写一个递归函数，不使用 * 运算符， 实现两个正整数的相乘。可以使用加号、减号、位移，但要吝啬一些。
		A * B = B +(A-1 ,b)

	管好当下，之后的事抛给递归

*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int multiply(int a, int b);
};

int main()
{
	Solution s;
	int a = 918795921;
	int b = 1;

	cout << s.multiply(a, b);

	return 0;
}

int Solution::multiply(int A, int B)
{
	if (A > 0)
	{
		//如果不交换，a特别大的情况下，可能爆栈
		int minVal = min(A, B);
		int maxVal = max(A, B);

		return maxVal + multiply(minVal - 1, maxVal);
	}

	return 0;
}
