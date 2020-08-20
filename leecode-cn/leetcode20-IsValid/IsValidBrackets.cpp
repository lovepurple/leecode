#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
	bool isValid(string s);

	bool isMatch(char left, char right);
};

int main()
{
	Solution s;
	string strInput = "]";
	cout << s.isValid(strInput);

	return 0;
}

bool Solution::isValid(string s)
{
	stack<char> charStack;
	for (int i = 0; i < s.length(); ++i)
	{
		char c = s[i];
		if (c == '[' || c == '{' || c == '(')
			charStack.push(c);
		else
		{
			if (charStack.empty())
				return false;

			char stackTopChar = charStack.top();
			if (isMatch(stackTopChar, c))
				charStack.pop();
			else
				return false;
		}
	}


	return charStack.empty();
}

bool Solution::isMatch(char left, char right)
{
	if (left == '[')
		return right == ']';

	if (left == '{')
		return right == '}';

	if (left == '(')
		return right == ')';

	return false;
}
