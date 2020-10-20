#include <iostream>
#include <stack>

using namespace std;

/*
	BST 
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
	int getMinimumDifference(TreeNode* root);
};

int main()
{
	TreeNode* pRootNode = new TreeNode(1);
	TreeNode* pNode1 = new TreeNode(3);
	TreeNode* pNode2 = new TreeNode(2);

	pRootNode->right = pNode1;
	pNode1->left = pNode2;

	Solution s;

	int minimumDifference = s.getMinimumDifference(pRootNode);
	cout << minimumDifference;

	return 0;
}

int Solution::getMinimumDifference(TreeNode* root)
{
	int previousVal = INT_MIN;
	int minimumDifference = INT_MAX;

	stack<TreeNode*> nodeStack;
	TreeNode* pCurrent = root;

	while (!nodeStack.empty() || pCurrent != nullptr)
	{
		while (pCurrent != nullptr)
		{
			nodeStack.push(pCurrent);
			pCurrent = pCurrent->left;
		}

		pCurrent = nodeStack.top();
		nodeStack.pop();

		if (previousVal == INT_MIN)
			previousVal = pCurrent->val;
		else
		{
			minimumDifference = min(minimumDifference, pCurrent->val - previousVal);
			previousVal = pCurrent->val;
		}

		pCurrent = pCurrent->right;
	}


	return minimumDifference;
}
