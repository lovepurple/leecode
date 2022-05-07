/*
	埃拉托斯特尼筛法
*/

#include <iostream>

using namespace std;


int countPrimes(int n)
{
	if (n <= 2)
		return 0;

	bool* isNotPrime = new bool[n] {false};
	/*
		开一个和数量大小一样的数组，
		如果没标记过 说明该数是质数，然后把当前质数所有的倍数标记为合数。
		如果标记过，不用标记，这个数就是合数

		
	*/

	int primesCount = 0;
	for (int i = 2; i < n; ++i)
	{
		if (!isNotPrime[i])
		{
			primesCount++;

			for (int j = 1; i * j < n; ++j)
			{
				isNotPrime[j * i] = true;
			}
		}
	}

	return primesCount;

}

int main()
{
	int count = countPrimes(100);

	cout << count << endl;
	return 0;
}