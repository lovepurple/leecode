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

int main()
{
	Solution s;
	Node* pRoot = new Node(1);
	pRoot->left = new Node(2);
	pRoot->right = new Node(3);
	pRoot->left->left = new Node(4);
	pRoot->left->right = new Node(5);
	pRoot->right->left = new Node(6);
	pRoot->right->right = new Node(7);

	s.connect(pRoot);

	return 0;
}

Node* Solution::connect(Node* root)
{
	if (root == nullptr)
		return nullptr;

	queue<Node*> nodeQueue;
	nodeQueue.push(root);

	while (!nodeQueue.empty())
	{
		int nodeCount = nodeQueue.size();
		Node* pPreviousNode = nullptr;
		for (int i = 0; i < nodeCount; ++i)
		{
			Node* pCurrentNode = nodeQueue.front();
			if (pPreviousNode == nullptr)
			{
				pPreviousNode = pCurrentNode;
			}
			else
			{
				pPreviousNode->next = pCurrentNode;
				pPreviousNode = pCurrentNode;
			}

			nodeQueue.pop();
			if (pCurrentNode->left)
				nodeQueue.push(pCurrentNode->left);

			if (pCurrentNode->right)
				nodeQueue.push(pCurrentNode->right);
		}
	}

	return root;
}