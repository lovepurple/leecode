/*
	�ݹ�+DP ��¥������

	https://leetcode-cn.com/problems/three-steps-problem-lcci/
*/
#include <iostream>

class Solution
{
public:
	int waysToStep(int n);
private:

	//std::unordered_map<long, int> m_cachMap;

};



int main()
{
	int totalStairs = 61;
	Solution solution;
	std::cout << solution.waysToStep(totalStairs);

	system("pause");
	return 0;
}

int Solution::waysToStep(int n)
{
	//todo:���ʹ�õݹ飬������ظ�̫�࣬ʹ�û����
	if (n <= 0)
		return 0;

	//n=1 n=2 n=3 ������ĵĽ�
	if (n == 1)
		return 1;

	if (n == 2)
		return 2;

	if (n == 3)
		return 4;

	//���ر��� ����ݹ�
	int* dpTable = new int[n + 1];
	dpTable[0] = 0;
	dpTable[1] = 1;
	dpTable[2] = 2;
	dpTable[3] = 4;

	//���ſ���,�������ȷ�ϳ�֮ǰ������
	for (int i = 4; i <= n; ++i)
	{
		//1000000007  ��int32������������mod 1000000007  ���Ա�ֵ֤ ��Զ��int��
		dpTable[i] = ((dpTable[i - 1] + dpTable[i - 2]) % 1000000007 + dpTable[i - 3]) % 1000000007;
		//dpTable[i] %= 1000000007;

	}



	return dpTable[n];
}
