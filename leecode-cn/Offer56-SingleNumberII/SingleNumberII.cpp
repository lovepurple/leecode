#include <iostream>
#include <vector>
/*
	位运算技巧

*/

using namespace std;


class Solution
{
public:
	int singleNumber(vector<int>& nums);
};

int main()
{
	vector<int> vecNums = { 5,2,2,2,5,5,4 };

	Solution s;
	cout << s.singleNumber(vecNums);

	return 0;
}

int Solution::singleNumber(vector<int>& nums)
{
	/*
	*  对于 {5,2,2,2,5,5,4} 的二进制为
			0101
			0010
			0010
			0010
			0101
			0101
			0100

		如果是3的倍数则每位上 1 的数量 mod 3 ==0

			{} & 0001
				 0010
				 0100
				 1000  分别计算每位上1的数量，如果mod3 == 1 则说明是单个的数

		int 一共32位 （一个符号位）
	*/

	int singleNumber = 0;
	for (int i = 0; i < 32; ++i)
	{
		int bitCount = 0;
		int bitMask = 1 << i;			//当前位的Mask

		for (int num : nums)
		{
			//表示目标数的二进制 在当前位上有值 
			if ((num & bitMask) != 0)
				bitCount++;
		}

		//不是3的倍数，要求的结果数占位了1
		if (bitCount % 3 != 0)
			singleNumber |= bitMask;
	}

	return singleNumber;
}
