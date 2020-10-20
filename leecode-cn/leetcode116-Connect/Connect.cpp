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

	Node* connectRecursion(Node* root);

	void helper(Node* pNode, bool isLeft);
};

int main()
{
	Solution s;
	Node* pRoot = new Node(-1);
	pRoot->left = new Node(0);
	pRoot->right = new Node(1);
	pRoot->left->left = new Node(2);
	pRoot->left->right = new Node(3);
	pRoot->right->left = new Node(4);
	pRoot->right->right = new Node(5);

	pRoot->left->left->left = new Node(6);
	pRoot->left->left->right = new Node(7);

	pRoot->left->right->left = new Node(8);
	pRoot->left->right->right = new Node(9);

	pRoot->right->left->left = new Node(10);
	pRoot->right->left->right = new Node(11);

	pRoot->right->right->left = new Node(12);
	pRoot->right->right->right = new Node(13);


	//s.connect(pRoot);
	Node* pAfterConnect = s.connectRecursion(pRoot);

	cout << pAfterConnect;

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

Node* Solution::connectRecursion(Node* root)
{
	if (root == nullptr)
		return nullptr;

	helper(root, false);

	return root;
}

/*
	技巧， right->next 可以使用 上一层父节点的next
*/
void Solution::helper(Node* pNode, bool isLeft)
{
	if (pNode == nullptr)
		return;

	if (pNode->left != nullptr)
		pNode->left->next = pNode->right;

	//技巧， right->next 可以使用 上一层父节点的next

	if (pNode->left && pNode->right)
	{
		if (pNode->next)
			pNode->right->next = pNode->next->left;

		helper(pNode->left, true);

		helper(pNode->right, false);
	}
}
