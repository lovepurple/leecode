/*
	DFS 解扫雷

	[['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'M', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E']]

	E表示没挖出
	M表示雷
	B表示没相邻
	数据表示旁边有几个雷
*/

#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click);

};
