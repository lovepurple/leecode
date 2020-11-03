#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	bool validMountainArray(vector<int>& A);
};

int main()
{
	Solution s;
	vector<int> vecInput = { 9,8,7,6,5,4,3,2,1 };
	cout << s.validMountainArray(vecInput);


	return 0;
}

bool Solution::validMountainArray(vector<int>& A)
{
	if (A.size() <= 2)
		return false;

	int mountainHeapIndex = 0;
	for (int i = 1; i < A.size(); ++i)
	{
		if (A[i] < A[i - 1])
		{
			mountainHeapIndex = i - 1;
			break;
		}
		else if (A[i] == A[i - 1])
			return false;
	}

	if (mountainHeapIndex == 0)
		return false;

	for (int i = A.size() - 2; i > mountainHeapIndex; --i)
	{
		if (A[i] <= A[i + 1])
			return false;
	}

	return true;
}
