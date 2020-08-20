#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	string multiply(string num1, string num2);

	string add(string num1, string num2);
};


int main()
{
	Solution s;
	string num1 = "123456789";
	string num2 = "987654321";
	cout << s.multiply(num1, num2) << endl;

	return 0;
}

string Solution::multiply(string num1, string num2)
{
	if (num1 == "0" || num2 == "0")
		return "0";


	if (num2.length() > num1.length())
	{
		string strTmp = num1;
		num1 = num2;
		num2 = strTmp;
	}

	string strRes = "";
	for (int i = 0; i < num2.length(); ++i)
	{
		string subRes = "";
		int charindexOfNum2 = num2.length() - 1 - i;
		int charOfNum2 = num2[num2.length() - i - 1] - '0';
		for (int j = 0; j < num1.length(); ++j)
		{
			int charOfNum1 = num1[num1.length() - j - 1] - '0';

			int multiplyVal = charOfNum1 * charOfNum2;
			string strMultiplyVal = to_string(multiplyVal);

			for (int k = j; k > 0; --k)
				strMultiplyVal.push_back('0');

			subRes = add(subRes, strMultiplyVal);
		}

		for (int k = i; k > 0; k--)
			subRes.push_back('0');

		strRes = add(strRes, subRes);
	}

	return strRes.length() == 0 ? "0" : strRes;
}


string Solution::add(string num1, string num2)
{
	if (num2 == "")
		return num1;

	if (num1 == "")
		return num2;


	if (num2.length() > num1.length())
	{
		string strTmp = num1;
		num1 = num2;
		num2 = strTmp;
	}

	string sumOfToStr = "";

	bool needAppend = false;
	for (int i = 0; i < num1.length(); ++i)
	{
		int charIndexOfNum1 = num1.length() - 1 - i;
		int charindexOfNum2 = num2.length() - 1 - i;

		char charNum1 = num1[charIndexOfNum1];
		int digNum1 = charNum1 - '0';
		int digNum2 = charindexOfNum2 >= 0 ? (num2[charindexOfNum2] - '0') : 0;

		if (digNum1 + digNum2 > 9)
		{
			if (charIndexOfNum1 - 1 >= 0)
				num1[charIndexOfNum1 - 1] += 1;
			else
				needAppend = true;//最后一位过10进位
		}

		char sumChar = (char)((digNum1 + digNum2) % 10) + '0';
		sumOfToStr.push_back(sumChar);

		//最后一位过10进位
		if (needAppend)
			sumOfToStr.push_back('1');
	}

	reverse(sumOfToStr.begin(), sumOfToStr.end());
	return sumOfToStr;
}
