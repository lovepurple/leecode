/*
	̰���㷨1��
		�����㿪�˼�С�꣬���ܵ���֧����Ǯ����Ļ���ֻ�� 25 �֡�10 �֡�5 �ֺ� 1 ������Ӳ�ң���������ۻ�Ա��Ҫ�Ҹ��ͻ� 41 ��Ǯ��Ӳ�ң�
		��ΰ��Ų����Ҹ����˵�Ǯ����ȷ��Ӳ�ҵĸ��������٣�

		������Ҫ��ȷ�ļ����㣺
		1.����ֻ�� 25 �֡�10 �֡�5 �ֺ� 1 ������Ӳ�ң�
		2.�Ҹ��ͻ� 41 ��Ǯ��Ӳ�ң�
		3.Ӳ�����ٻ�
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
		cout << it->first << "��" << it->second << "��" << endl;



	system("pause");
	return 1;

}