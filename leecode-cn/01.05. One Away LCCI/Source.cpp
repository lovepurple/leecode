#include <iostream>

using namespace std;

//Ë«Ö¸ÕëÎÊÌâ
bool onEditAway(string first, string second)
{
	if (abs((int)(first.length() - second.length())) > 1)
		return false;

	if (first.length() > second.length())
	{
		string temp = first;
		first = second;
		second = temp;
	}


	int editTimes = 0;
	int j = 0;
	for (int i = 0; i < first.length();)
	{
		if (first[i] != second[j])
		{
			editTimes++;

			if (editTimes > 1)
				return false;

			if (first.length() < second.length()) {
				j++;
				continue;
			}
		}
		j++;
		i++;
	}

	return true;
}

int main()
{
	string first = "hus";
	string second = "pus";

	cout << onEditAway(first, second);

	return 0;
}