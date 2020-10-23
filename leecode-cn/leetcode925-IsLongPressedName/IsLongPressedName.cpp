#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	bool isLongPressedName(string name, string typed);
};

int main()
{
	Solution s;
	string name = "zlexya";
	string typed = "aazlllllllllllllleexxxxxxxxxxxxxxxya";

	cout << s.isLongPressedName(name, typed);

	return 0;
}

bool Solution::isLongPressedName(string name, string typed)
{
	if (name.size() > typed.size())
		return false;

	int indexName = 0;
	int indexTyped = 0;
	while (indexName < name.size() && indexTyped < typed.size())
	{
		if (name[indexName] == typed[indexTyped])
		{
			indexName++;
			indexTyped++;
		}
		else
		{
			if (indexTyped > 0 && typed[indexTyped] == typed[indexTyped - 1])
				indexTyped++;
			else
				return false;
		}
	}

	while (indexTyped < typed.size())
	{
		if (typed[indexTyped] != typed[indexTyped - 1])
			return false;

		indexTyped++;
	}

	return indexName == name.size();
}
