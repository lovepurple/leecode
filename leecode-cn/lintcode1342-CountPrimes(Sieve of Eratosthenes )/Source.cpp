/*
	������˹����ɸ��
*/

#include <iostream>

using namespace std;


int countPrimes(int n)
{
	if (n <= 2)
		return 0;

	bool* isNotPrime = new bool[n] {false};
	/*
		��һ����������Сһ�������飬
		���û��ǹ� ˵��������������Ȼ��ѵ�ǰ�������еı������Ϊ������
		�����ǹ������ñ�ǣ���������Ǻ���

		
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