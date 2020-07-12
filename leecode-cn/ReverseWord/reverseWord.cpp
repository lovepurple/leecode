/*
	递归反转字符串， 思想。。。
*/
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:

	string reverseWord(string& str);

	string reserseWordInternal(string& str, int index);
};

string Solution::reverseWord(string& str)
{
	return reserseWordInternal(str, 0);
}

string Solution::reserseWordInternal(string& str, int index)
{
	if (index < str.size())
	{
		char c1 = str.at(index);

		return reserseWordInternal(str, index + 1) + c1;
	}

	return "";
}
int main()
{
	string str = "wo shi ni da ye";

	Solution s;
	string str2 = s.reverseWord(str);

	cout << str2 << endl;

	system("pause");
	return 0;
}