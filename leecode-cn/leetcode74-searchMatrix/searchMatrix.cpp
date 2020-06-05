/**
 * 二分查找
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	struct CORRELATION_VECTOR
	{
		int x;
		int y;
	};

public:
	Solution();
	~Solution();

	bool searchMatrix(vector<vector<int>>& matrix, int target);

	CORRELATION_VECTOR getCorrelationOfMatrix(int indexOf1D, const vector<vector<int>>& matrix, CORRELATION_VECTOR& out)
	{
		int rows = matrix.size();
		int cols = matrix.begin()->size();


		out.x = indexOf1D / cols;
		out.y = indexOf1D % cols;

		return out;
	}


private:

};

Solution::Solution()
{
}

Solution::~Solution()
{
}

bool Solution::searchMatrix(vector<vector<int>>& matrix, int target)
{
	if (matrix.size() == 0)
		return false;

	//输入[[]] 边界问题
	if (matrix.begin()->begin() == matrix.begin()->end())
		return false;

	int l = 0;
	int r = matrix.size() * matrix.begin()->size() - 1;
	CORRELATION_VECTOR midIndex;

	while (l <= r)
	{
		int mid = l + (r - l) / 2;

		getCorrelationOfMatrix(mid, matrix, midIndex);

		if (target < matrix[midIndex.x][midIndex.y])
			r = mid - 1;
		else if (target > matrix[midIndex.x][midIndex.y])
			l = mid + 1;
		else
			return true;
	}

	if (l == r)
		return matrix[midIndex.x][midIndex.y] == target;

	return false;
}

int main()
{
	//vector<vector<int>> matrix = {
	//	{1,3,5,7},
	//	{10,11,16,20},
	//	{23,30,34,50}
	//};
	//vector<vector<int>> matrix =
	//{
	//	{1,3,5,7},
	//	{10,11,16,20},
	//	{23,30,34,50}
	//};
	vector<vector<int>> matrix = { {1} };

	int target = 1;

	Solution solution;
	cout << solution.searchMatrix(matrix, target);

	return 0;
}