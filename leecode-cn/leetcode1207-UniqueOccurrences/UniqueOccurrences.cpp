#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
	bool uniqueOccurrences(vector<int>& arr);
private:
	void qSort(vector<int>& arr, int indexLeft, int indexRight);
};

int main()
{
	Solution s;
	vector<int> arr = { 1,2 };
	cout << s.uniqueOccurrences(arr);

	return 0;
}

bool Solution::uniqueOccurrences(vector<int>& arr)
{
	qSort(arr, 0, arr.size() - 1);
	unordered_set<int> uniqueSet;

	for (int i = 0; i < arr.size();)
	{
		int num = arr[i];
		int times = 0;
		for (int j = i; j < arr.size(); ++j)
		{
			if (arr[j] == num)
				times++;
			else
			{
				i = j;

				if (uniqueSet.find(times) == uniqueSet.end())
					uniqueSet.insert(times);
				else
					return false;


			}
		}
	}

	return true;
}

void Solution::qSort(vector<int>& arr, int indexLeft, int indexRight)
{
	if (indexLeft > indexRight)
		return;

	int pivot = arr[indexLeft];
	int l = indexLeft;
	int r = indexRight;

	while (l < r)
	{
		while (pivot <= arr[r] && l < r)
			r--;

		while (pivot >= arr[l] && l < r)
			l++;

		if (l < r)
		{
			int tmp = arr[l];
			arr[l] = arr[r];
			arr[r] = tmp;
		}
	}

	if (pivot > arr[l])
	{
		int tmp = arr[indexLeft];
		arr[indexLeft] = arr[l];
		arr[l] = tmp;
	}

	qSort(arr, indexLeft, l - 1);
	qSort(arr, l + 1, indexRight);
}
