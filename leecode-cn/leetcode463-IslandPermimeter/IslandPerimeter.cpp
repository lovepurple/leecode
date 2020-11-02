#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int islandPerimeter(vector<vector<int>>& grid);
private:
	void dfs(vector<vector<int>> grid, int indexRow, int indexCol, int& islandCount, vector<vector<bool>>& visited);
};

int main()
{
	vector<vector<int>> grid =
	{
		{0,1,0,0},
		{1,1,1,1},
		{0,0,0,0},
		{1,0,0,0}
	};

	Solution s;
	int count = s.islandPerimeter(grid);
	cout << count;

	return 0;
}

//边的数量 = 2 + 正文形连在一起的数量  * 2
int Solution::islandPerimeter(vector<vector<int>>& grid)
{
	if (grid.size() == 0)
		return 0;

	int count = 0;
	vector<vector<bool>> vecVisited(grid.size(), vector<bool>(grid[0].size()));
	for (int i = 0; i < grid.size(); ++i)
	{
		for (int j = 0; j < grid[0].size(); ++j)
		{
			if (grid[i][j] == 1)
			{
				dfs(grid, i, j, count, vecVisited);
				return 2 + count * 2;
			}
		}
	}


	return count;

}

void Solution::dfs(vector<vector<int>> grid, int indexRow, int indexCol, int& islandCount, vector<vector<bool>>& visited)
{
	if (indexRow >= grid.size() || indexRow < 0)
		return;

	if (indexCol >= grid[0].size() || indexCol < 0)
		return;

	if (grid[indexRow][indexCol] == 1 && !visited[indexRow][indexCol])
	{
		islandCount++;

		visited[indexRow][indexCol] = true;

		dfs(grid, indexRow - 1, indexCol, islandCount, visited);
		dfs(grid, indexRow + 1, indexCol, islandCount, visited);
		dfs(grid, indexRow, indexCol + 1, islandCount, visited);
		dfs(grid, indexRow, indexCol - 1, islandCount, visited);
	}
}
