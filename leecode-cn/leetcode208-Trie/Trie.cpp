#include <iostream>
#include <string>

using namespace std;

class TrieNode
{
public:
private:
	//Trie* m_next;
};



/**
 * 每个Ties对象为一个层级的节点  每个Trie持有 26个字母的TieNode 每个TieNode连接下一层级的Trie
 */
class Trie
{
public:
	Trie();

	void insert(string word);

	bool search(string word);

	bool startsWith(string prefix);

private:
	Trie* m_levelNodes[26] = {};		//指针数组 26个 Trie* ,后面加{} 表示都是nullptr，如果不加，会是野指针
	bool m_isWordEnd = false;
	char m_wordCharacter = '\0';
};


int main()
{
	Trie* pTrie = new Trie();
	pTrie->insert("add");
	//pTrie->insert("app");

	cout << pTrie->search("ad") << endl;
	//cout << pTrie->search("app") << endl;

	return 0;
}

Trie::Trie()
{
}

void Trie::insert(string word)
{
	Trie* pLookupLevel = this;

	//逐层级构建，每个字符对应一个子层级   1-> n的关系
	for (int i = 0; i < word.size(); ++i)
	{
		char c = word[i];
		Trie* pLevelNode = pLookupLevel->m_levelNodes[c - 'a'];
		if (pLevelNode == nullptr)
		{
			pLevelNode = new Trie();
			pLookupLevel->m_levelNodes[c - 'a'] = pLevelNode;
			m_wordCharacter = c;
		}

		pLookupLevel = pLevelNode;
		if (i == word.size() - 1)
			pLookupLevel->m_isWordEnd = true;
	}
}


/*
	索引与startswith的不同在于，索引需要完全匹配word词(最后一个字符isend = true)
*/
bool Trie::search(string word)
{
	Trie* pLoopupLevel = this;
	for (char c : word)
	{
		Trie* pLevelNode = pLoopupLevel->m_levelNodes[c - 'a'];
		if (pLevelNode == nullptr)
			return false;

		pLoopupLevel = pLevelNode;
	}

	return pLoopupLevel->m_isWordEnd;
}

bool Trie::startsWith(string prefix)
{
	Trie* pLookupLevel = this;

	for (char c : prefix)
	{
		Trie* pLevelTrie = pLookupLevel->m_levelNodes[c - 'a'];
		if (pLevelTrie == nullptr)
			return false;

		pLookupLevel = pLevelTrie;
	}

	return true;
}
