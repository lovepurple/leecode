#include <iostream>

using namespace  std;

/**
 * m*n �ĳ˷���ÿһ��С�ڵ���x �ĸ����� min(x/i ,n)
 */

int findKthNumber(int m, int n, int k)
{
	if (m <= 0 || n <= 0 || k <= 0)
		return 0;

	//m*n�ĳ˷��� ���ֵ �� m*m
	if (k > m * n)
		return m * n;

	//���ַ��ƽ�
	int left = 1;
	int right = m * n;

	while (left < right)
	{
		int mid = (left + right) / 2;

		//Mid == leftʱ�Ľ��п�
		//if (mid == left)
		//	return mid;

		int count = 0;		//i�������Ż� 
		for (int i = 1; i <= m; ++i)
			count += min(mid / i, n);

		// count == k��ʱ�� ��ʱ��mid�п��ܲ��ڳ˷����� ��������
		if (count >= k)
			right = mid;
		else if (count < k)
			left = mid + 1;
	}

	return left;
}

int main()
{
	int m = 2;
	int n = 3;

	//Ѱ�ҵ�kthС����
	int kth = 6;

	cout << findKthNumber(m, n, kth);

	return 0;
}