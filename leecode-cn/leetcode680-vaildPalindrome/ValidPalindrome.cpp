/*
	双指针（对撞指针应用）
*/
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	bool validPalindrome(string s);
};


int main()
{
	string strInput = "cupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupucu";

	Solution s;

	cout << s.validPalindrome(strInput) << endl;

	system("pause");
	return 0;
}

bool Solution::validPalindrome(string s)
{
	int indexFront = 0;
	int indexBack = s.size() - 1;

	bool hasDeleteChar = false;
	while (indexFront < indexBack)
	{
		if (s[indexFront] == s[indexBack])
		{
			indexBack--;
			indexFront++;
		}
		else
		{
			if (hasDeleteChar)
				return false;

			if (s[indexBack] == s[indexFront + 1])
			{
				indexFront += 1;
				hasDeleteChar = true;
			}
			else if (s[indexBack - 1] ==s[indexFront])
			{
				indexBack -= 1;
				hasDeleteChar = true;
			}
			else
				return false;

		}

	}

	return true;
}
