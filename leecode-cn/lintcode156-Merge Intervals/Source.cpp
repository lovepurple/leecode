#include <iostream>
#include <vector>

using namespace std;


class Interval {
public:
	int start, end;
	Interval(int start, int end)
	{
		this->start = start;
		this->end = end;
	}
};

void mergeTwoCollection(Interval mergingCollection, vector<Interval>& resultCollections)
{
	Interval currentInterval = resultCollections[resultCollections.size() - 1];




}


vector<Interval> merge(vector< Interval>& intervals)
{
	if (intervals.size() == 1)
		return intervals;

	vector<Interval> mergedCollections;
	mergedCollections.push_back(intervals[0]);

	for (int i = 1; i < intervals.size(); ++i)
		mergeTwoCollection(intervals[i], mergedCollections);

	return mergedCollections;
}



int main()
{
	return 0;
}