#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int>> permute(vector<int>& nums);

private:
	vector<vector<int>> permute(vector<int>& nums, int cursor, int index, vector<vector<int>>& permResults);

	vector<int> swap(vector<int>& nums, int index0, int index1);

};

int main()
{
	vector<int> input = { 1,2,3,4 };

	Solution s;

	vector<vector<int>> output = s.permute(input);



	system("pause");
	return 0;
}

vector<vector<int>> Solution::permute(vector<int>& nums)
{
	vector<vector<int>> result;
	for (int i = 0; i < nums.size(); ++i)
	{
		result = permute(nums, i, 0, result);
	}

	return result;
}

vector<vector<int>> Solution::permute(vector<int>& nums , int cursor, int index, vector<vector<int>>& permResults)
{
	if (index < nums.size())
	{
		swap(nums, cursor, index);
		vector<int> vec2;
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
			vec2.push_back(*it);

		permResults.push_back(vec2);
		permute(nums, cursor, index + 1, permResults);

		swap(nums, index, cursor);

	}

	return permResults;
}

vector<int> Solution::swap(vector<int>& nums, int index0, int index1)
{
	int temp = nums[index0];
	nums[index0] = nums[index1];
	nums[index1] = temp;

	return nums;
}
