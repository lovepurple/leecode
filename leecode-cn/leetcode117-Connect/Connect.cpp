#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
	Node* connect(Node* root);
};

Node* Solution::connect(Node* root)
{
	if (root == nullptr)
		return nullptr;

	queue<Node*> nodeQueue;
	nodeQueue.push(root);

	while (!nodeQueue.empty())
	{
		int levelNodeSize = nodeQueue.size();

		Node* pPreviousNode = nullptr;
		for (int i = 0; i < levelNodeSize; ++i)
		{
			Node* pNode = nodeQueue.front();
			if (pPreviousNode == nullptr)
				pPreviousNode = pNode;
			else
			{
				pPreviousNode->next = pNode;
				pPreviousNode = pNode;
			}

			if (pNode->left != nullptr)
				nodeQueue.push(pNode->left);

			if (pNode->right != nullptr)
				nodeQueue.push(pNode->right);

			nodeQueue.pop();
		}
	}

	return root;
}
