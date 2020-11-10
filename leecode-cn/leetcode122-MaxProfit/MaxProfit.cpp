#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int maxProfit(vector<int>& prices)
{
	if (prices.size() < 2)
		return 0;

	int sumOfProfit = 0;
	stack<int> monotonStack;
	for (int i = 0; i < prices.size(); ++i)
	{
		if (monotonStack.empty())
		{
			monotonStack.push(prices[i]);
		}
		else
		{
			int stackTop = monotonStack.top();
			if (prices[i] > stackTop)
			{
				monotonStack.push(prices[i]);
			}
			else if (prices[i] < stackTop)
			{
				if (monotonStack.size() == 1)
				{
					monotonStack.pop();
					monotonStack.push(prices[i]);
				}
				else
				{
					int stackBottomVal = monotonStack.top();
					while (!monotonStack.empty())
					{
						stackBottomVal = monotonStack.top();
						monotonStack.pop();
					}

					if (stackTop > stackBottomVal)
						sumOfProfit += stackTop - stackBottomVal;

					monotonStack.push(prices[i]);
				}
			}
		}
	}

	int stackTop = monotonStack.top();
	while (monotonStack.size() > 1)
		monotonStack.pop();

	if (stackTop > monotonStack.top())
		sumOfProfit += stackTop - monotonStack.top();

	return sumOfProfit;
}

int main()
{
	vector<int> nums = { 7,6,4,3,1 };
	int max = maxProfit(nums);

	cout << max;

	return 0;
}