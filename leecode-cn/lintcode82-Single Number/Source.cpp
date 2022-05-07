
#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& a) {
	//a.erase()
	while (a.size() > 0)
	{
		int currentElement = a[0];
		bool hasSame = false;
		for (int i = 1; i < a.size(); ++i)
		{
			if (currentElement == a[i])
			{
				hasSame = true;
				a.erase(a.begin() + i);
			}
		}

		if (hasSame)
			a.erase(a.begin());
		else
			return a[0];
	}

	return  a[0];
}

int main()
{
	vector<int> vec({ 0,0,1,0,0 });
	cout << singleNumber(vec);

	return 0;
}