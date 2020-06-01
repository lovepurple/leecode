/*
	https://leetcode-cn.com/problems/kids-with-the-greatest-number-of-candies/
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	Solution();
	~Solution();

	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies);

private:

};

Solution::Solution()
{
}

Solution::~Solution()
{
}

vector<bool> Solution::kidsWithCandies(vector<int>& candies, int extraCandies)
{
	vector<bool> result(candies.size());
	int maxCandies = candies[0];

	for (vector<int>::iterator it = candies.begin(); it != candies.end(); ++it)
		maxCandies = maxCandies > * it ? maxCandies : *it;

	int index = 0;
	for (vector<int>::iterator it = candies.begin(); it != candies.end(); ++it)
		result[index++] = (*it + extraCandies) >= maxCandies;

	return result;

}

int main()
{
	vector<int> candies = { 2,3,5,1,3 };
	int extraCandies = 3;
	Solution solution;
	vector<bool> result = solution.kidsWithCandies(candies, extraCandies);

	return 0;
}