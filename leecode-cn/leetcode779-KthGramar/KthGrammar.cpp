#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	int kthGrammar(int N, int K);

	string helper(int n, string str);

};

int main()
{
	Solution s;
	int n = 4;
	int k = 5;

	cout << s.kthGrammar(n, k);
	return 0;
}

int Solution::kthGrammar(int N, int K)
{
	string val = helper(N, "0");
	return (int)val[K - 1] - '0';
}

string Solution::helper(int n, string str)
{
	if (n > 0)
	{
		string str2;
		for (int i = 0; i < str.length(); ++i)
		{
			if (str[i] == '0')
				str2.append("01");
			else if (str[i] == '1')
				str2.append("10");
		}

		return helper(n - 1, str2);
	}

	return str;
}
