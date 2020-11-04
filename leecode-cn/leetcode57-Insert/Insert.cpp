#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{
	vector<vector<int>> vecInsertResult;
	bool newIntervalInserted = false;
	for (vector<int> interval : intervals)
	{
		/*
				------
						 #######
		*/
		if (interval[1] < newInterval[0])
		{
			vecInsertResult.push_back(interval);
		}
		/*
				   -------
			#####
		*/
		else if (interval[0] > newInterval[1])
		{
			if (!newIntervalInserted)
			{
				vecInsertResult.push_back(newInterval);
				newIntervalInserted = true;
			}
			vecInsertResult.push_back(interval);
		}
		/*
				------
					#######

					------
				#######
		*/
		else
		{
			/*	if (!newIntervalInserted)
				{*/
				//vecInsertResult.push_back({ min(interval[0],newInterval[0]),max(interval[1],newInterval[1]) });
				//newIntervalInserted = true;
			//}

			newInterval[0] = min(newInterval[0], interval[0]);
			newInterval[1] = max(newInterval[1], interval[1]);
		}
	}

	//处理放在最后的情况
	if (!newIntervalInserted)
		vecInsertResult.push_back(newInterval);


	return vecInsertResult;
}

int main()
{
	vector<vector<int>> intervals = {
		{1,2},
		{3,5},
		{6,7},
		{8,10},
		{12,16},
	};

	vector<int> newInterval = { 4,8 };

	cout << insert(intervals, newInterval).size();

	return 0;
}