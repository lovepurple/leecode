/*
	并查集算法， 两次操作  并  -> 查
	1. 根据== != 构造并集，
	2. 二次遍历判断等式是否有同一个根


	== 构造并集时， ==可以看作同一根

*/
#include <iostream>	
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	Solution();
	~Solution();

	bool equationsPossible(vector<string>& equations);

	int findRoot(unordered_map<char, int> unionCollection, char element);

	void unionelement(unordered_map<char, int>& collection, char elementA, char elementB);

private:


};

Solution::Solution()
{
}

Solution::~Solution()
{
}



int Solution::findRoot(unordered_map<char, int> unionCollection, char element)
{
	unordered_map<char, int>::iterator iter = unionCollection.find(element);
	return iter != unionCollection.end() ? iter->second : -1;
}

void Solution::unionelement(unordered_map<char, int>& collection, char elementA, char elementB)
{
	int elementARoot = findRoot(collection, elementA);
	int elementBRoot = findRoot(collection, elementB);

	if (elementARoot == elementBRoot)
	{
		if (elementARoot == -1)
		{
			collection[elementA] = elementA - 64;
			collection[elementB] = elementA - 64;
		}
	}
	else
	{
		if (elementARoot == -1)
		{
			collection[elementA] = elementBRoot;
		}

		if (elementBRoot == -1)
		{
			collection[elementB] = elementARoot;
		}
	}

}

bool Solution::equationsPossible(vector<string>& equations)
{
	unordered_map<char, int> unionsMap;
	//并查集求解

	for (vector<string>::iterator it = equations.begin(); it != equations.end(); ++it)
	{
		char variableA = it->at(0);
		char variableB = it->at(3);


		//并集
		if (it->at(1) == '=')
		{
			unionelement(unionsMap, variableA, variableB);
		}
		else
		{
			int root = findRoot(unionsMap, variableA);
			if (root == -1)
				unionsMap[variableA] = variableA - 64;

			root = findRoot(unionsMap, variableB);
			if (root == -1)
				unionsMap[variableB] = variableB - 64;
		}
	}

	//第二次 查 查并集中的条件是否冲突
	for (vector<string>::iterator it = equations.begin(); it != equations.end(); ++it)
	{
		char variableA = it->at(0);
		char variableB = it->at(3);

		if (it->at(1) == '=')
		{
			if (unionsMap[variableA] != unionsMap[variableB])
				return false;
		}


		if (it->at(1) == '!')
		{
			if (unionsMap[variableA] == unionsMap[variableB])
				return false;
		}
	}

	return true;
}


int main()
{
	/*vector<string> input =
	{
		"a==b",
		"b!=a"
	};*/
	vector<string> input = { "c==c","f!=a","f==b","b==c" };

	Solution solution;
	cout << solution.equationsPossible(input);

	return 0;
}