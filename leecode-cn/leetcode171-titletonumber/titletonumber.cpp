/*
	https://leetcode-cn.com/problems/excel-sheet-column-number/
*/
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	Solution();
	~Solution();

	int titleToNumber(string s);
private:

};

Solution::Solution()
{
}

Solution::~Solution()
{
}

int Solution::titleToNumber(string s)
{
	int val = 0;
	for (int i = s.size() - 1; i >= 0; --i)
	{
		int bitNumber = 1;
		int power = s.size() - 1 - i;
		while (power > 0)
		{
			bitNumber *= 26;
			power--;
		}
		val += ((int)s[i] + 1 - 'A') * bitNumber;
	}

	return val;
}


int main()
{
	string strInput = "AB";
	Solution solution;
	cout << solution.titleToNumber(strInput);

	return 0;
}