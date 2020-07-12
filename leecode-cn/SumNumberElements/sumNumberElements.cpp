#include <iostream>

int sumNumberElement(int number)
{
	if (number == 0)
		return 0;

	return number % 10 + sumNumberElement(number / 10);
}


int main()
{
	int srcNumber = 1234456;

	int result = sumNumberElement(srcNumber);

	system("pause");
	return 0;
}