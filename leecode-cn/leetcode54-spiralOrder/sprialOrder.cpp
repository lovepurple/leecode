/*
	使用转置矩阵实现逆时针打印Matrix
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	Solution();
	~Solution();

	vector<int> sprialOrder(vector<vector<int>>& matrix);

	void transposeMatrix(vector<vector<int>>& matrixBeforeTranspose);
};

Solution::Solution()
{
}

Solution::~Solution()
{
}

vector<int> Solution::sprialOrder(vector<vector<int>>& matrix)
{
	vector<int>* result = new vector<int>();
	while (matrix.size() > 0)
	{
		vector<vector<int>>::iterator iterRow = matrix.begin();
		for (vector<int>::iterator iter = iterRow->begin(); iter != iterRow->end(); ++iter)
		{
			result->push_back(*iter);
		}
		matrix.erase(iterRow);

		if (matrix.size() > 0)
			this->transposeMatrix(matrix);
	}

	return *result;
}

void Solution::transposeMatrix(vector<vector<int>>& matrixBeforeTranspose)
{
	int row = matrixBeforeTranspose[0].size();
	int col = matrixBeforeTranspose.size();

	//声明2D的Vector
	vector<vector<int>> transpose(row, vector<int>(col));

	//转置矩阵的算法
	for (int j = 0; j < col; ++j)
	{
		for (int i = 0; i < row; ++i)
		{
			transpose[i][j] = matrixBeforeTranspose[j][row - i - 1];
		}
	}

	matrixBeforeTranspose = transpose;

	//C++变量的作用域问题
	//return transpose;
}

int main()
{
	vector<vector<int>> vec{ { 1, 2, 3 },
						 { 4, 5, 6 },
						 { 7, 8, 9 } };
	Solution solution;

	vector<int> spiralMatrix = solution.sprialOrder(vec);
	//solution.transposeMatrix(vec);

	//2D vector的遍历
	for (vector<int>::iterator itRow = spiralMatrix.begin(); itRow != spiralMatrix.end(); ++itRow)
	{
		cout << *itRow << ",";
	}

	//delete& spiralMatrix;

	return 0;
}
