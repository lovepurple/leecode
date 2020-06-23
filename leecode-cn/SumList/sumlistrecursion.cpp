#include <iostream>
#include <random>

struct Node
{
	int nodeValue;
	Node* pNext;

	Node(int nodeval) :nodeValue(nodeval), pNext(NULL) {}
};

class Solution
{
public:
	int sumList(Node* pRoot);
};


int main()
{
	int nodeCount = 10;
	Node* pRoot = NULL;

	Node* pTemp = nullptr;
	for (int i = 0; i < nodeCount; ++i)
	{
		Node* pNode = new Node(i);
		std::cout << pNode->nodeValue << std::endl;

		if (pRoot == nullptr)
		{
			pRoot = pNode;
			pTemp = pNode;
		}
		else
		{
			pTemp->pNext = pNode;
			pTemp = pNode;
		}

	}

	std::cout << "===========================" << std::endl;

	Solution solution;
	int sumOfList = solution.sumList(pRoot);

	std::cout << sumOfList << std::endl;

	Node* pNodePtr;
	while (pRoot!= nullptr)
	{
		pNodePtr = pRoot;
		pRoot = pRoot->pNext;

		delete pNodePtr;
	}

	system("pause");
	return 1;
}

int Solution::sumList(Node* pRoot)
{
	if (pRoot == NULL)
		return 0;

	//直到最后一个再回归

	return pRoot->nodeValue + sumList(pRoot->pNext);
}
