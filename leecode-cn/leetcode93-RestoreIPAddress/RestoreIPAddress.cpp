#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
	回溯法。

*/
class Solution
{
public:
	vector<string> restoreIpAddress(string s);

	///dfs 或递归通常没有返回值

	/// <summary>
	/// 回溯
	/// </summary>
	/// <param name="strSource">原始IP字符串</param>
	/// <param name="indexFrom">当前开始的Index</param>
	/// <param name="ipDepth">第几位IP</param>
	/// <param name="strIp">当前拼接出的IP结果</param>
	/// <param name="answerVec">所有结果列表</param>		
	void backTrace(string strSource, int indexFrom, int ipDepth, string& strIp, vector<string>& answerVec);
};


int main()
{
	Solution solution;
	string s = "101023";

	vector<string> result = solution.restoreIpAddress(s);

	cout << result.size();

	return 0;
}

vector<string> Solution::restoreIpAddress(string s)
{
	vector<string> vecAnswer;
	if (s.size() == 0)
		return vecAnswer;

	string strIPAddress = "";
	backTrace(s, 0, 0, strIPAddress, vecAnswer);

	return vecAnswer;
}

void Solution::backTrace(string strSource, int indexFrom, int ipDepth, string& strIp, vector<string>& answerVec)
{
	//由于是在下一次递归里确定结果，这里indexFrom 和 ipDepth都超前一个
	if (ipDepth == 4 && indexFrom == strSource.size())
	{
		string strAnswer = strIp.substr(0, strIp.size() - 1);		//使用substr实际是字符串拷贝
		answerVec.push_back(strAnswer);
		return;
	}

	//2 5 5 2552550  位数的问题，一共最多3 * 4 = 12位，当前depth剩下的位数的问题
	int maxStrSize = (4 - ipDepth) * 3;
	if (strSource.size() - indexFrom > maxStrSize)
		return;

	//各种剪枝
	for (int i = 0; i < 3; ++i)
	{
		//越界 剪枝
		if (indexFrom + i >= strSource.size())
			break;

		//开头是0x 0xx的问题
		if (strSource[indexFrom] == '0' && i > 0)
			break;

		//是否是0~255
		string depthOfIP = strSource.substr(indexFrom, i + 1);
		if (stoi(depthOfIP) <= 255)
		{
			strIp.append(depthOfIP);
			strIp.push_back('.');

			//下一层递归
			backTrace(strSource, indexFrom + i + 1, ipDepth + 1, strIp, answerVec);

			//将本次结果移除（拷贝出来，） 本质递归就是对栈的模拟 ,
			strIp = strIp.substr(0, strIp.size() - depthOfIP.size() - 1);		//相当于strIp是本次迭代初的（退回到上一层）
		}
	}
}

