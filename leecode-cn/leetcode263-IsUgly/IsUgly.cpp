#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	const vector<int> PRIMES = { 2,3,5 };
	bool isUgly(int num);
};

int main()
{
	Solution s;
	int num = 1;

	cout << s.isUgly(num);

	return 0;
}

bool Solution::isUgly(int num)
{
	if (num == 0)
		return false;

	if (num == 1)
		return true;

	for (int prime : PRIMES)
	{
		int modVal = num % prime;

		if (modVal == 0)
		{
			num /= prime;
			return isUgly(num);			//递归return xxx() 最后返回的就是下层的值不会再继续下面的return
		}
	}

	return false;
}
