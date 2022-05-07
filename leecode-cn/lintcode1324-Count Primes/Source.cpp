#include <iostream>

using namespace  std;

bool isPrimes(int number) {

	if (number <= 3)
		return true;

	int numberSqrt = std::sqrt(number);

	for (int i = 2; i <= numberSqrt; i += 1)
	{
		if (number % i == 0)
			return false;
	}

	cout << number << endl;
	return true;
}

int countPrimes(int n) {
	int primeCount = 0;

	if (n <= 2)
		return 0;

	for (int i = 3; i < n; i += 2)
	{
		if (isPrimes(i))
			primeCount++;
	}

	return primeCount + 1;
}


int main()
{
	cout << countPrimes(100);

	return 0;
}