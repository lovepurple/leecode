/*
	�� 1+2+...+n ��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����


*/

#include <iostream>

class Solution
{
public:
	Solution();
	~Solution();

	int sumNums(int n);
};

Solution::Solution()
{
}

Solution::~Solution()
{
}

int Solution::sumNums(int n)
{
	int result = n;
	/*
		���ɣ����� && �Ķ�· + �ݹ�
		 A && B  ���A = false �� B��ִ�У�

		 ����
			n = 2
			sum = 2
			2 >0 && sum+=
						n = 1
						sum = 1
						1 > 0 && sum +=
										n=0
										sum = 0
										flag = 0>0
										return 0;
						return 1
			return 3

			�Եݹ�����
	*/

	n > 0 && (result += sumNums(n - 1)) > 0;
	
	return result;
}

int main()
{
	int n = 2;
	Solution solution;
	std::cout << solution.sumNums(n);


	return 0;
}