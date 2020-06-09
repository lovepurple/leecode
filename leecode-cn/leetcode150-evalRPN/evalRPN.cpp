#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
	Solution();
	~Solution();

	/// <summary>
	/// 计算逆波兰式
	/// </summary>
	/// <param name="tokens"></param>
	/// <returns></returns>
	int evalRNP(vector<string>& tokens);


	int is_number(const string& s);
};

Solution::Solution()
{
}

Solution::~Solution()
{
}

int Solution::evalRNP(vector<string>& tokens)
{
	vector<int> resultStack;
	for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); ++it)
	{
		if (is_number(*it))
		{
			resultStack.push_back(stoi(*it));
		}
		else
		{
			int numberB = resultStack.back();
			resultStack.pop_back();

			int numberA = resultStack.back();
			resultStack.pop_back();

			int tempResult;
			if (*it == "+")
				tempResult = numberA + numberB;
			else if (*it == "-")
				tempResult = numberA - numberB;
			else if (*it == "*")
				tempResult = numberA * numberB;
			else if (*it == "/")
				tempResult = numberA / numberB;

			resultStack.push_back(tempResult);
		}
	}

	return resultStack.back();
}

int Solution::is_number(const string& s)
{
	if (*s.begin() == '-')
	{
		if (s.size() == 1)
			return false;

		return all_of(s.begin() + 1, s.end(), [](unsigned char c) { return isdigit(c); });
	}

	//C++ 11  写法 lambda表达式
	return !s.empty() && ((*s.begin()) == '-' || all_of(s.begin(), s.end(), [](unsigned char c) { return isdigit(c); }));
}

int main()
{
	//vector<string> input = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	vector<string> input = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
	Solution solution;
	int rpnResult = solution.evalRNP(input);
	cout << rpnResult;


	return 1;
}