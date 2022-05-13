#include <iostream>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t)
{
	unordered_map<char, int> charMap;
	for (int i = 0; i < s.length(); ++i)
	{
		if (charMap.find(s[i]) != charMap.end())
		{
			charMap[s[i]] += 1;
		}
		else
			charMap.insert({ s[i], 1 });
	}

	for (int i = 0; i < t.length(); ++i)
	{
		auto it = charMap.find(t[i]);

		if (it == charMap.end())
			return false;

		it->second -= 1;
		if (it->second == 0)
			charMap.erase(t[i]);
	}

	return charMap.size() == 0;
}

int main()
{
	string s = "anagram";
	string t = "nagaram";

	cout << isAnagram(s, t);

	return 0;
}