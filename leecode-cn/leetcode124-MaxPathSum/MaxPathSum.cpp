#include <iostream>
/*
	求二叉树最大路径的和
		使用dfs计算一个子树的和（递归还得多练）


		root + left
		root + right
		root + left +right

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
	int maxPathSum(TreeNode* root);

	int dfs(TreeNode* pNode, int maxVal);
};

int main()
{
	Solution s;
	TreeNode* pRoot = new TreeNode(1);
	TreeNode* pL10 = new TreeNode(-2);
	TreeNode* pL11 = new TreeNode(-3);
	TreeNode* pL20 = new TreeNode(1);
	TreeNode* pL21 = new TreeNode(3);
	TreeNode* pL22 = new TreeNode(-2);
	TreeNode* pL30 = new TreeNode(-1);

	pL20->left = pL30;
	pL10->left = pL20;
	pL10->right = pL21;
	pL11->left = pL22;

	pRoot->left = pL10;
	pRoot->right = pL11;
	/*pL11->left = pL23;
	pL11->right = pL24;*/

	cout << s.maxPathSum(pRoot);

	return 0;
}


int Solution::maxPathSum(TreeNode* root)
{
	return dfs(root, INT_MIN);
}

int Solution::dfs(TreeNode* pNode, int maxVal)
{
	if (pNode == nullptr)
		return INT_MIN;

	int leftSubTreeSum = dfs(pNode->left, maxVal);
	int rightSubTreeSum = dfs(pNode->right, maxVal);

	int sumOfNode = 0;

	if (pNode->val < 0)
	{
		sumOfNode = max(max(leftSubTreeSum, pNode->val), rightSubTreeSum);
	}
	else
	{
		sumOfNode = pNode->val;

		if (leftSubTreeSum > 0)
			sumOfNode += leftSubTreeSum;

		if (rightSubTreeSum > 0)
			sumOfNode += rightSubTreeSum;
	}

	maxVal = max(maxVal, sumOfNode);
	return maxVal;
}
