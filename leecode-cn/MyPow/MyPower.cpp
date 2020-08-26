#include <iostream>

class Solution
{
public:
	double myPow(double x, int n);
};

double Solution::myPow(double x, int n)
{
	if (n == 0)
		return 1;

	if (n == 1)
		return x;

	if (n < 0)
	{
		x = 1 / x;
		n = -n;
	}

	n = n / 2;
	if (n < 0)
		n = -n;


	if (n % 2 == 1)
		return x * myPow((x * x), n);
	else
		return myPow((x * x), n);
}

int main()
{
	Solution s;
	std::cout << s.myPow(2, 10);


	return 0;
}
