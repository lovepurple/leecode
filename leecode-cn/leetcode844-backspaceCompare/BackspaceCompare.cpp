#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	bool backspaceCompare(string S, string T);

	void removeBackspace(string& S);
};

int main()
{
	Solution s;
	string S = "rh";
	string T = "#rh";

	cout << s.backspaceCompare(S, T);

	return 0;
}

/*
	双指针 倒序
*/
bool Solution::backspaceCompare(string S, string T)
{
	removeBackspace(S);
	removeBackspace(T);

	return S == T;
}

void Solution::removeBackspace(string& S)
{
	int backspaceCount = 0;
	for (int i = S.size() - 1; i >= 0; --i)
	{
		while (i >= 0 && S[i] == '#')
		{
			S.erase(S.begin() + i);
			backspaceCount++;
			i--;
		}

		while (i >= 0 && backspaceCount > 0)
		{
			if (S[i] == '#')
			{
				S.erase(S.begin() + i);
				backspaceCount++;
				break;
			}
			else
			{
				S.erase(S.begin() + i);
				backspaceCount--;
			}
			if (backspaceCount > 0)
				i--;
		}
	}
}
