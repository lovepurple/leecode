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
	int num = 8;

	cout << s.isUgly(num);

	return 0;
}

bool Solution::isUgly(int num)
{
	if (num == 0)
		return false;

	for (int prime : PRIMES)
	{
		int modVal = num % prime;

		if (modVal == 0)
		{
			if (num / prime != 1)
			{
				num /= prime;
				return isUgly(num);
			}
		}
	}

	return std::find(PRIMES.begin(), PRIMES.end(), num) != PRIMES.end() || num == 1;
}
