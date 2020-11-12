#include <iostream>
#include <vector>

using namespace std;

vector<int> sortArrayByParityII(vector<int>& A)
{
	vector<int> vecOdd;
	vector<int> vecEven;
	for (int i = A.size() - 1; i >= 0; --i)
	{
		if (A[i] % 2 != 0)
			vecOdd.push_back(A[i]);
		else
			vecEven.push_back(A[i]);
	}

	for (int i = 0; i < vecOdd.size(); ++i)
	{
		A[i * 2] = vecEven[i];
		A[i * 2 + 1] = vecOdd[i];
	}

	return A;
}
int main()
{
	vector<int> A = { 4,2,5,7 };
	sortArrayByParityII(A);

	return 0;
}