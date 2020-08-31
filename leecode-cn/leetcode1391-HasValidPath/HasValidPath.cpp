#include <iostream>
#include <vector>

/*

	路径的连通问题。
*/
using namespace std;

class Solution
{
public:
	bool hasValidPath(vector<vector<int>>& grid);

	bool dfs(vector<vector<int>>& grid, int row, int col, vector<vector<bool>> isVisited);
};

int main()
{
	Solution s;

	vector<vector<int>> grid = { {2,4,3},{ 6,5,2} };

	cout << s.hasValidPath(grid);

	return 0;
}

bool Solution::hasValidPath(vector<vector<int>>& grid)
{
	vector<vector<bool>> isVisited(grid.size(), vector<bool>(grid[0].size()));
	return dfs(grid, 0, 0, isVisited);
}

bool Solution::dfs(vector<vector<int>>& grid, int row, int col, vector<vector<bool>> isVisited)
{
	if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
		return false;

	if (row == grid.size() - 1 && col == grid[0].size() - 1)
		return true;

	if (isVisited[row][col])
		return false;

	isVisited[row][col] = true;

	int nextRow = row;
	int nextCol = col;
	if (grid[row][col] == 1)
	{
		if (col - 1 < 0 || isVisited[row][col - 1])
			nextCol = col + 1;
		else
			nextCol = col - 1;
	}
	else if (grid[row][col] == 2)
	{
		if (row - 1 < 0 || isVisited[row - 1][col])
			nextRow = row + 1;
		else
			nextRow = row - 1;
	}
	else if (grid[row][col] == 3)
	{
		if (col - 1 < 0 || isVisited[row][col - 1])
			nextRow = nextRow + 1;
		else
			nextCol = col - 1;
	}
	else if (grid[row][col] == 4)
	{
		if (col + 1 >= grid.size() || isVisited[row + 1][col])
			nextCol = col + 1;
		else
			nextRow = nextRow + 1;

	}
	else if (grid[row][col] == 5)
	{
		if (col - 1 < 0 || isVisited[row][col - 1])
			nextRow = nextRow - 1;
		else
			nextCol = col - 1;
	}
	else /*if (grid[row][col] == 6)*/
	{
		if (row - 1 < 0 || isVisited[row - 1][col])
			nextCol = col + 1;
		else
			nextRow = nextRow - 1;
	}

	return dfs(grid, nextRow, nextCol, isVisited);
}
