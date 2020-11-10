/*
	单调栈。

	接雨水 维护单调递减栈（ 顶到底是减的， 入栈顺序是增的。。 相反的关系）

*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int trap(vector<int>& height)
{
	int sumArea = 0;
	stack<int> monotonIndexStack;
	for (int i = 0; i < height.size(); ++i)
	{
		int trapHeight = height[i];
		if (trapHeight == 0)
			continue;

		if (monotonIndexStack.empty())
		{
			monotonIndexStack.push(i);
			continue;
		}


		int stackTopIndex = monotonIndexStack.top();
		int stackTopHeight = height[stackTopIndex];

		if (trapHeight < stackTopHeight)
		{
			monotonIndexStack.push(i);
			continue;
		}

		while (!monotonIndexStack.empty())
		{

		}


		while (!monotonIndexStack.empty() && stackTopHeight < trapHeight)
		{
			stackTopIndex = monotonIndexStack.top();
			stackTopHeight = height[stackTopIndex];
			monotonIndexStack.pop();
		}

		sumArea += (i - stackTopIndex - 1) * min(trapHeight, stackTopHeight);
		monotonIndexStack.push(i);

	}

	return sumArea;
}

int main()
{
	vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	int trapArea = trap(height);

	cout << trapArea;

	return 0;
}