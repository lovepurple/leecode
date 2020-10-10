#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	void reverseString(vector<char>& s);
};

void Solution::reverseString(vector<char>& s)
{
	int index_begin = 0;
	int index_end = s.size() - 1;

	while (index_begin <= index_end)
	{
		char tmp = s[index_begin];
		s[index_begin] = s[index_end];
		s[index_end] = tmp;

		index_begin++;
		index_end--;
	}
}
