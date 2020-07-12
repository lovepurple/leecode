#include <iostream>
#include <string>

using namespace std;
class Solution
{
public:
	string reverseVowels(string s);

	bool isVowel(char c);
};

int main()
{
	Solution s;
	string sInput = "holle";
	cout << s.reverseVowels(sInput) << endl;

	system("pause");
	return 0;
}

string Solution::reverseVowels(string s)
{
	int frontIndex = 0;
	int backIndex = s.size() - 1;

	while (frontIndex < backIndex)
	{
		char cFront = s.at(frontIndex);
		char cBack = s.at(backIndex);

		if (!isVowel(cFront))
			frontIndex++;

		if (!isVowel(cBack))
			backIndex--;

		if (isVowel(cFront) && isVowel(cBack))
		{
			char temp = s[frontIndex];
			s[frontIndex] = s[backIndex];
			s[backIndex] = temp;

			frontIndex++;
			backIndex--;
		}
	}

	return s;
}

bool Solution::isVowel(char c)
{
	if (c < 97)
		c += 32;

	return c == 'a'  || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
