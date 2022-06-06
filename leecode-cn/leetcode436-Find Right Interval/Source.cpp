#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int GetRightIntervalIndex(const vector<int> orderedStarts, int targetEnd, const unordered_map<int, int> intervalIndexMap)
{
	int left = 0;
	int right = orderedStarts.size() - 1;

	while (left <= right)
	{
		if (left == right)
			return intervalIndexMap.find(orderedStarts[left])->second;

		int mid = (left + right) / 2;
		int midStart = orderedStarts[mid];

		if (midStart >= targetEnd)
			right = mid;
		else
			left = mid + 1;
	}

	return -1;
}

vector<int> findRightInterval(vector<vector<int>>& intervals)
{
	unordered_map<int, int> intervalIndexMap;

	vector<int> intervalStarts;
	for (vector<vector<int>>::iterator it = intervals.begin(); it != intervals.end(); ++it)
	{
		intervalIndexMap.insert({ (*it)[0], distance(intervals.begin(), it) });
		intervalStarts.push_back((*it)[0]);
	}

	sort(intervalStarts.begin(), intervalStarts.end());

	vector<int>* pResult = new vector<int>();

	//interval 的区间后
	//todo:leetcode不知道为什么超时 SB
	for (auto interval : intervals)
	{
		int intervalEnd = interval[1];
		if (intervalEnd > intervalStarts[intervalStarts.size() - 1])
		{
			pResult->push_back(-1);
			continue;
		}

		int index = GetRightIntervalIndex(intervalStarts, intervalEnd, intervalIndexMap);
		pResult->push_back(index);
	}

	return *pResult;
}





int main()
{
	vector<vector<int>> nums = { {3,4} ,{2,3}, {1,2} };

	vector<int> indexs = findRightInterval(nums);

	for (auto index : indexs)
		cout << index << "->";

	return 0;
}