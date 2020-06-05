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
	if (rows == 0)
		return false;

	//二次二分？
	int upRowIndex = 0;
	int downRowIndex = (rows - 1);

	//二分查找的这里是<=更方便
	while (upRowIndex <= downRowIndex)
	{
		int midIndex = upRowIndex + (downRowIndex - upRowIndex) / 2;

		vector<int> rowDatas = matrix[midIndex];
		int rowSize = rowDatas.size();
		if (rowDatas[0] > target)
			downRowIndex = midIndex - 1;
		else if (rowDatas[rowSize - 1] < target)
			upRowIndex = midIndex ddd+ 1;
		else
		{
			//再次二分
			int l = 0;
			int r = rowSize - 1;

			while (l <= r)
			{
				int mid = l + (r - l) / 2;
				if (rowDatas[mid] > target)
					r = mid - 1;
				else if (rowDatas[mid] < target)
					l = mid + 1;
				else
					return true;
			}



			return false;
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
	int target = 5;
	cout << solution.searchMatrixII(matrix, target);

	return 0;
}