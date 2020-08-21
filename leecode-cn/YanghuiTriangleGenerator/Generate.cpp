#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int>> generate(int numRows);

	vector<int> generateRow(int rowNum, vector<int> vecLastRow);
};

int main()
{
	Solution s;
	s.generate(1);

	return 0;
}

vector<vector<int>> Solution::generate(int numRows)
{
	vector<vector<int>> result;
	if (numRows == 0)
		return result;

	for (int i = 0; i < numRows; ++i)
	{
		vector<int> row = vector<int>(i + 1);

		for (int j = 0; j < row.size(); ++j)
		{
			if (j == 0 || j == row.size() - 1)
				row[j] = 1;
			else
			{
				row[j] = result[i - 1][j] + result[i - 1][j - 1];
			}
		}
		result.push_back(row);
	}


	return result;
}
