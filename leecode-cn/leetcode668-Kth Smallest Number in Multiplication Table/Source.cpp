#include <iostream>

using namespace  std;

/**
 * m*n 的乘法表，每一行小于等于x 的个数是 min(x/i ,n)
 */

int findKthNumber(int m, int n, int k)
{
	if (m <= 0 || n <= 0 || k <= 0)
		return 0;

	//m*n的乘法表 最大值 是 m*m
	if (k > m * n)
		return m * n;

	//二分法逼近
	int left = 1;
	int right = m * n;

	while (left < right)
	{
		int mid = (left + right) / 2;

		//Mid == left时的解有可
		//if (mid == left)
		//	return mid;

		int count = 0;		//i还可以优化 
		for (int i = 1; i <= m; ++i)
			count += min(mid / i, n);

		// count == k的时候 这时的mid有可能不在乘法表中 继续二分
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

	//寻找第kth小的数
	int kth = 6;

	cout << findKthNumber(m, n, kth);

	return 0;
}