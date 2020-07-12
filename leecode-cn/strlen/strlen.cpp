#include <iostream>
#include <string>

using namespace std;

int strlength(const char* str)
{
	if (*str != '\0')
		return strlength(str + 1) + 1;

	return 0;
}


int main()
{
	//ÒªÓÐconst
	const char* str = "wo shi ni daye";

	cout << strlength(str);

	system("pause");
	return 0;
}