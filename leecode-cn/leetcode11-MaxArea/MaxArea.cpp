#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int maxArea(vector<int>& height);
};

int main()
{
	Solution s;
	vector<int> heightVec = { 1,8,6,2,5,4,8,3,7 };

	cout << s.maxArea(heightVec);

	return 0;
}

/*
	双指针求解，
		Area = (IndexMax - IndexMin) * Min(height[IndexMax],height[IndexMin])

	移动指针的策略：移动两个数中较小的，因为(IndexMax-IndexMin) 一定在减少，
		Min(height[IndexMax],height[IndexMin]) 如果移动大的那个，没变化，

*/
int Solution::maxArea(vector<int>& height)
{
	int maxAreaOfHeight = 0;

	int indexBegin = 0;
	int indexEnd = height.size() - 1;

	int areaWidth, areaHeight;

	while (indexBegin < indexEnd)
	{
		areaWidth = indexEnd - indexBegin;
		areaHeight = height[indexBegin] > height[indexEnd] ? height[indexEnd--] : height[indexBegin++];

		maxAreaOfHeight = max(maxAreaOfHeight, areaWidth * areaHeight);
	}

	return maxAreaOfHeight;
}
