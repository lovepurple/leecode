#include <iostream>
#include <vector>
/*
	典型DFS 矩阵



*/

using namespace std;

class Solution
{
public:
	bool exist(vector<vector<char>>& board, string word);

	bool dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited, const string word, int characterIndex);

	//优化空间复杂度
	bool existOptimize(vector<vector<char>>& board, string word);

	bool dfs(vector<vector<char>>& board, int i, int j, const string word, int charIndex);
};

int main()
{
	Solution s;
	vector<vector<char>> vecBoard =
	{
		//{'A', 'B', 'C', 'E'},
		//{'S', 'F', 'C', 'S'},
		//{'A', 'D', 'E', 'E'}
		{'A','A'}
	};
	string strWord = "AAA";

	cout << s.exist(vecBoard, strWord);
	return 0;
}

bool Solution::exist(vector<vector<char>>& board, string word)
{
	vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
	for (int i = 0; i < board.size(); ++i)
	{
		/*
			以每一个[i,j] 为起点进行枚举，

			这里不能将走过的点标记为已走过
				visited是全局的，标记为已走过 可能存在搜索结果是反走的情况
					[[ a ,b ,c]
					str="cba" 如果 将a b 标记为已走过，dfs无法往回走。

		*/
		for (int j = 0; j < board[0].size(); ++j)
		{
			if (dfs(board, i, j, visited, word, 0))
				return true;

		}
	}


	return false;
}

bool Solution::dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited, const string word, int characterIndex)
{
	/*
		dfs套路，把退出条件写前头，越界，

	*/

	if (i > board.size() - 1 || j > board[0].size() - 1 || i < 0 || j < 0 || visited[i][j])
	{
		return false;
	}
	else
	{
		char c = board[i][j];

		if (c != word[characterIndex])
			return false;

		//当所有目标都搜索完毕之后 返回成功
		if (characterIndex == word.length() - 1)
			return true;

		/*
			标记当前节点已走过 并探寻下一个节点

			上 下 左 右 只要有一个方向true 继续走

				这里使用 || or 操作符，只要一个true后面的不走

			之后将当前点标记回 防止对全局有影响
		*/
		visited[i][j] = true;


		bool res = dfs(board, i + 1, j, visited, word, characterIndex + 1) ||
			dfs(board, i - 1, j, visited, word, characterIndex + 1) ||
			dfs(board, i, j + 1, visited, word, characterIndex + 1) ||
			dfs(board, i, j - 1, visited, word, characterIndex + 1);

		visited[i][j] = false;

		return res;
	}


}

bool Solution::existOptimize(vector<vector<char>>& board, string word)
{
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[0].size(); ++j)
		{
			if (dfs(board, i, j, word, 0))
				return true;
		}
	}

	return false;
}

bool Solution::dfs(vector<vector<char>>& board, int i, int j, const string word, int charIndex)
{
	//越界
	if (i > board.size() - 1 || i<0 || j>board[0].size() - 1 || j < 0)
		return false;

	//访问过了
	if (board[i][j] == '#')
		return false;

	if (word[charIndex] != board[i][j])
		return false;


	if (charIndex == word.length() - 1)
		return true;

	char visitedChar = board[i][j];
	board[i][j] = '#';

	bool goNext = dfs(board, i + 1, j, word, charIndex + 1) ||
		dfs(board, i - 1, j, word, charIndex + 1) ||
		dfs(board, i, j + 1, word, charIndex + 1) ||
		dfs(board, i, j - 1, word, charIndex + 1);

	board[i][j] = visitedChar;


	return goNext;
}
