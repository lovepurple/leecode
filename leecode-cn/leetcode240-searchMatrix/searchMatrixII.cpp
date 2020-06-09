#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	Solution();
	~Solution();

	bool searchMatrixII(vector<vector<int>>& matrix, int target);

private:

};

Solution::Solution()
{
}

Solution::~Solution()
{
}

bool Solution::searchMatrixII(vector<vector<int>>& matrix, int target)
{
	int rows = matrix.size();
	int cols = matrix.begin()->size();

	int stepRow = rows / 2;
	int stepCol = cols / 2;

	for (int i = 0; i < rows; i += stepRow + 1)
	{
		for (int j = 0; j < cols; j += stepCol + 1)
		{
			if (i >= rows || j >= cols)
				return false;

			int blockMin = matrix[i][j];
			int blockMax = matrix[i + stepRow][j + stepRow];

			if (target >= blockMin && target <= blockMax)
			{
				cout << i;
				cout << j;

			}
		}

	}



	return false;
}

int main()
{
	//左右有顺序  上下有顺
	vector<vector<int>> matrix =
	{
		{1,4,7,11,15},
		{2,5,8,12,19},
		{3,6,9,16,22},
		{10,13,14,17,24},
		{18,21,23,26,30}
	};

	Solution solution;
	int target = 25;
	cout << solution.searchMatrixII(matrix, target);

	return 0;
}