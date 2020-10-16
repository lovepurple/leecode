#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> sortedSquares(vector<int>& A);


	void quickSort(vector<int>& arr, int indexFrom, int indexEnd);
private:
	void Swap(vector<int>& arr, int a, int b);
};

int main()
{
	Solution s;
	vector<int> nums = { -1,0,1,1 };

	s.quickSort(nums, 0, nums.size() - 1);

	return 0;
}


vector<int> Solution::sortedSquares(vector<int>& A)
{
	if (A.size() == 0)
		return vector<int>();

	quickSort(A, 0, A.size() - 1);
	for (int i = 0; i < A.size(); ++i)
		A[i] = A[i] * A[i];

	return A;
}

void Solution::quickSort(vector<int>& arr, int indexFrom, int indexEnd)
{
	if (indexFrom >= arr.size() || indexEnd < 0)
		return;

	if (indexFrom >= indexEnd)
		return;


	int i = indexFrom;
	int j = indexEnd;
	int pivot = arr[indexFrom];		//不用+1

	while (i < j)
	{
		//有个等号的问题
		while (abs(pivot) <= abs(arr[j]) && i < j)
			j--;

		while (abs(pivot) >= abs(arr[i]) && i < j)
			i++;

		if (i < j)
			Swap(arr, i, j);
	}

	if (abs(pivot) > abs(arr[i]))
		Swap(arr, indexFrom, i);

	quickSort(arr, indexFrom, i - 1);
	quickSort(arr, i + 1, indexEnd);
}

void Solution::Swap(vector<int>& arr, int a, int b)
{
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}
