/*
	求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。


*/

#include <iostream>

class Solution
{
public:
	Solution();
	~Solution();

	int sumNums(int n);
};

Solution::Solution()
{
}

Solution::~Solution()
{
}

int Solution::sumNums(int n)
{
	int result = n;
	/*
		技巧：利用 && 的短路 + 递归
		 A && B  如果A = false 则 B不执行，

		 例：
			n = 2
			sum = 2
			2 >0 && sum+=
						n = 1
						sum = 1
						1 > 0 && sum +=
										n=0
										sum = 0
										flag = 0>0
										return 0;
						return 1
			return 3

			对递归的理解
	*/

	n > 0 && (result += sumNums(n - 1)) > 0;
	
	return result;
}

int main()
{
	int n = 2;
	Solution solution;
	std::cout << solution.sumNums(n);


	return 0;
}