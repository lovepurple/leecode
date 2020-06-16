/*
	贪心算法1：
		假设你开了间小店，不能电子支付，钱柜里的货币只有 25 分、10 分、5 分和 1 分四种硬币，如果你是售货员且要找给客户 41 分钱的硬币，
		如何安排才能找给客人的钱既正确且硬币的个数又最少？

		这里需要明确的几个点：
		1.货币只有 25 分、10 分、5 分和 1 分四种硬币；
		2.找给客户 41 分钱的硬币；
		3.硬币最少化
*/
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	Solution();
	~Solution();

	unordered_map<int, int> changeCoin(int totalNum, const vector<int>& coinList);



};

Solution::Solution()
{

}

Solution::~Solution()
{
}

unordered_map<int, int> Solution::changeCoin(int totalNum, const vector<int>& coinList)
{
	unordered_map<int, int> resultMap;
	for (vector<int>::const_iterator it = coinList.begin(); it != coinList.end(); ++it)
	{
		while (totalNum >= *it)
		{
			if (resultMap.find(*it) == resultMap.end())
				resultMap.insert({ *it,1 });
			else
				resultMap[*it] = resultMap[*it] + 1;

			totalNum -= *it;
		}
	}

	return resultMap;
}

int main()
{
	Solution solution;

	int totalNum = 41;
	vector<int> coins = { 25,10,5,1 };
	unordered_map<int, int> changeResult = solution.changeCoin(totalNum, coins);

	for (unordered_map<int, int>::iterator it = changeResult.begin(); it != changeResult.end(); ++it)
		cout << it->first << "，" << it->second << "个" << endl;



	system("pause");
	return 1;

}