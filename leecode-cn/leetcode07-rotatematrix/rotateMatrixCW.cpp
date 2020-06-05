/*
	˳ʱ����ת����
	��Ϊ�����������Ŀռ䣬��������ʱ�ֲ�����Ⱦ��ԭ���ݣ���ת���Σ� ���� �Խ�
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	Solution();
	~Solution();

	void rotate(vector<vector<int>>& matrix);


};

Solution::Solution()
{
}

Solution::~Solution()
{
}


void Solution::rotate(vector<vector<int>>& matrix)
{
	int rows = matrix.size();

	vector<vector<int>>::iterator it = matrix.begin();
	int cols = matrix.begin()->size();

	//��ֱ��ת
	for (int i = 0; i < rows / 2; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[rows - i - 1][j];
			matrix[rows - i - 1][j] = temp;
		}
	}

	//�ԽǷ�ת
	for (int i = 1; i < rows; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (i != j)
			{
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;
			}
		}
	}
}

int main()
{
	vector<vector<int>> matrix =
	{
		/*{5,1,9,11},
		{2,4,8,10},
		{13,3,6,7},
		{15,14,12,16}*/
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	Solution solution;
	solution.rotate(matrix);

	return 0;
}
