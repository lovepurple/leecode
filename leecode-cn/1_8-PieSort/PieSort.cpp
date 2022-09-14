/*
	编程之美 烙饼排序方法，来回翻转
*/
#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int> vecPie)
{
	for (auto it = begin(vecPie); it != end(vecPie); ++it) {
		cout << *it << "->";
	}
	cout << endl;
}

int findBiggestPie(const vector<int> vecPie, int findEndIndex)
{
	int biggestPieIndex = 0;
	int biggestPie = -1;
	for (int i = 0; i <= findEndIndex; ++i)
	{
		if (vecPie[i] > biggestPie)
		{
			biggestPieIndex = i;
			biggestPie = vecPie[i];
		}
	}
	return biggestPieIndex;
}

/**
 * 翻转
 */
void flip(vector<int>& vecPies, int flipDstIndex)
{
	for (int i = 0; i <= flipDstIndex / 2; ++i)
	{
		if (i == flipDstIndex - i)
			break;

		int temp = vecPies[i];
		vecPies[i] = vecPies[flipDstIndex - i];
		vecPies[flipDstIndex - i] = temp;
	}
}


void sort(vector<int>& vecPie)
{
	for (int i = vecPie.size() - 1; i >= 0; --i)
	{
		int biggestPieIndex = findBiggestPie(vecPie, i);
		if (biggestPieIndex == i)
			continue;

		flip(vecPie, biggestPieIndex);
		flip(vecPie, i);

	}
}

int main()
{
	vector<int> vecPie = { 3,2,1,6,5,4,9,8,7,0 };

	cout << "Before Sort:" << endl;
	print(vecPie);

	cout << "After Sort:" << endl;
	sort(vecPie);
	print(vecPie);

	return 0;
}