#include <iostream>
#include <string>

using namespace std;
class Solution
{
public:
	bool judgeCirle(string moves);
};

int main()
{
	Solution s;
	string strInput = "UD";
	cout << s.judgeCirle(strInput);

	return 0;
}

bool Solution::judgeCirle(string moves)
{
	if (moves.size() % 2 != 0)
		return false;

	int horizontal = 0;
	int vertical = 0;

	for (int i = 0; i < moves.size(); ++i)
	{
		switch (moves[i])
		{
		case 'U':
			vertical += 1;
			break;;
		case 'D':
			vertical -= 1;
			break;
		case 'L':
			horizontal -= 1;
			break;
		case 'R':
			horizontal += 1;
			break;
		}
	}

	return horizontal == 0 && vertical == 0;
}