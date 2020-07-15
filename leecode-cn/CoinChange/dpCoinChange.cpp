/*
	有三种硬币，分别为2，5，7 ，每种都足够多， 买一本快需要27元，如何使用最少的硬币组合正好付清。

	1. 最大最小值问题，使用动态规划
	2. 状态，最后一步是  2，5，或7  那么前一步是  27-2 ,27-5,27-7


	状态转移方程：
		f(x) = 最少用多少枚硬币拼出x
*/

#include <iostream>
#include <vector>

using namespace std;

int getCoinCount(const vector<int> coinList, int total);

int main()
{
	return 0;
}
