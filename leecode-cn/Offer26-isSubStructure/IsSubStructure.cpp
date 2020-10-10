#include <iostream>
#include <queue>
#include <stack>

using namespace std;
/*
	判断B子树是否是A树的一部分，
	 二叉树中序遍历
		2 3 2 1
		3 null 2 2  使用中序就有问题。。。。


	update:2020-10-10 12:14:43  递归是个好东西。

*/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	bool isSubStructure(TreeNode* A, TreeNode* B);

	bool isSameTree(TreeNode* pTreeNode1, TreeNode* pTreeNode2);


};

int main()
{

	Solution s;
	TreeNode* pRoot = new TreeNode(3);
	pRoot->left = new TreeNode(4);
	pRoot->right = new TreeNode(5);
	pRoot->left->left = new TreeNode(1);
	pRoot->left->right = new TreeNode(2);

	TreeNode* pRootB = new TreeNode(4);
	pRootB->left = new TreeNode(1);

	cout << s.isSubStructure(pRoot, pRootB);

	return 0;
}

bool Solution::isSubStructure(TreeNode* A, TreeNode* B)
{
	if (A == nullptr || B == nullptr)
		return false;

	stack<TreeNode*> treeNodeStack;
	TreeNode* pCurrent = A;

	while (!treeNodeStack.empty() || pCurrent != nullptr)
	{
		while (pCurrent != nullptr)
		{
			bool isSubTree = false;
			if (pCurrent->val == B->val)
				isSubTree = isSameTree(pCurrent, B);

			if (isSubTree)
				return true;

			treeNodeStack.push(pCurrent);
			pCurrent = pCurrent->left;
		}

		pCurrent = treeNodeStack.top();
		treeNodeStack.pop();

		pCurrent = pCurrent->right;
	}

	return false;
}

bool Solution::isSameTree(TreeNode* pTreeNode1, TreeNode* pTreeNode2)
{
	if (pTreeNode1->val != pTreeNode2->val)
		return false;

	bool isSameSubTree = true;
	if (pTreeNode2->left != nullptr)
	{
		if (pTreeNode1->left == nullptr)
			return false;

		isSameSubTree &= isSameTree(pTreeNode1->left, pTreeNode2->left);
	}

	if (pTreeNode2->right != nullptr)
	{
		if (pTreeNode1->right == nullptr)
			return false;

		isSameSubTree &= isSameTree(pTreeNode1->right, pTreeNode2->right);
	}

	return isSameSubTree;
}


