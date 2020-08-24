#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	bool repeatedSubstringPattern(string s);
};

int main()
{
	Solution s;
	string strInput = "babbabbabbabbab";

	cout << s.repeatedSubstringPattern(strInput);
	return 0;
}

bool Solution::repeatedSubstringPattern(string s)
{

	/* 思路比较有意思    s %2 !=0 不能加这个 因为 abaabaaba 也是个重复子串
		字符串拼接的思路：
		 s + s 将输入的串复制一次， 如果原s 是由相同的子串组成则 相同的部分至少2次 再复制一次 至少相同部分4次

		 去掉拼接后的首字母和尾之后  中间部分需要包含一次s

		 a baa abaa abaa aba a

	*/
	string strCopy = s + s;
	strCopy = strCopy.substr(1, strCopy.size() - 2);

	//C++ find()要是没找到 返回不是-1 是特殊标记string::npos
	return strCopy.find(s) != string::npos;
}
