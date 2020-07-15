#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	Solution();
	~Solution();

	vector<int> twoSum(vector<int>& nums, int target);

private:

};

Solution::Solution()
{
}

Solution::~Solution()
{
}

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
	vector<int> result(2);
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
	{
		result[0] = distance(nums.begin(), it);
		for (vector<int>::iterator it2 = nums.begin() + distance(nums.begin(), it) + 1; it2 != nums.end(); ++it2)
		{
			if (*it + *it2 == target)
			{
				result[1] = distance(nums.begin(), it2);
				return result;
			}
		}
	}

	result.clear();


	return result;
}

int main()
{
	vector<int> nums = { 3,2,4 };
	int target = 6;
	Solution solution;

	//result 会引起对象拷贝 所以通通常C++都是返回值当参数传到函数中
	const vector<int> result = solution.twoSum(nums, target);


	return 0;
}