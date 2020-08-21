#include <iostream>
/*
	反转一个数的算法：
		reverseNumber = 0;

		while(num / 10)
			reverseNumber = reverseNumber * 10 + num % 10

			上一次乘10表示进一位 再加上本次的

*/

class Solution
{
public:
	bool isPalindrome(int x);
};

int main()
{
	Solution s;
	int num = 10;

	std::cout << s.isPalindrome(num);

	return 0;
}

bool Solution::isPalindrome(int x)
{
	//最低位是0的 一定不是
	if (x < 0 || x % 10 ==0)
		return false;

	if (x <= 9)
		return true;

	int num = x;
	int reverseNumber = 0;

	//反转一半的实现，当 reverseNumber 第一次 > num 时，可确定,可少遍历一半的数字。
	while (num > reverseNumber)
	{
		reverseNumber = reverseNumber * 10 + num % 10;
		num = num / 10;
	}

	if (num == reverseNumber)
		return true;

	//最后剩下的数是0 一定不是回文
	if (num == 0)
		return false;

	return reverseNumber / 10 == num;
}
