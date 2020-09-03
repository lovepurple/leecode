#include <iostream>

/**
 *	自底向上的递归
 *
 *
 *
 */

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution
{
public:
	bool isBalanced(TreeNode* root);

	int isBalance(TreeNode* pTreeNode);
};

int main()
{
	Solution s;
	TreeNode* root = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(2);
	TreeNode* node4 = new TreeNode(3);
	TreeNode* node5 = new TreeNode(3);
	TreeNode* node6 = new TreeNode(4);
	TreeNode* node7 = new TreeNode(4);

	node3->right = node5;
	node5->right = node7;

	node2->left = node4;
	node4->left = node6;

	root->left = node2;
	root->right = node3;

	cout << s.isBalanced(root);
	return 0;
}

bool Solution::isBalanced(TreeNode* root)
{
	return isBalance(root) != -1;
}

/**
 *	自底到上的策略
 *		平题需要呆着没事合计合计。
 *		使用-1 为递归出口
 *			只管当下，剩下交给递归
 * 
 *	自顶到下需要重复计算的太多
 *	
 */
int Solution::isBalance(TreeNode* pTreeNode)
{
	if (pTreeNode == nullptr)
		return 0;

	int leftDepth = isBalance(pTreeNode->left);
	if (leftDepth == -1)
		return -1;

	int rightDepth = isBalance(pTreeNode->right);
	if (rightDepth == -1)
		return -1;

	if (abs(leftDepth - rightDepth) > 1)
		return -1;

	return 1 + max(leftDepth, rightDepth);
}