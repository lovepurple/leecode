#include <iostream>
#include <stack>

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
	int kthLargest(TreeNode* root, int k);

	int helper(TreeNode* pNode, int k);
};

int main()
{
	TreeNode* pRootNode = new TreeNode(5);

	pRootNode->left = new TreeNode(3);
	pRootNode->right = new TreeNode(6);
	pRootNode->left->left = new TreeNode(2);
	pRootNode->left->right = new TreeNode(4);
	pRootNode->left->left->left = new TreeNode(1);

	Solution s;
	int k = 3;
	int kthLargestNum = s.kthLargest(pRootNode, k);
	cout << kthLargestNum;


	return 0;
}

int Solution::kthLargest(TreeNode* root, int k)
{
	stack<TreeNode*> nodeStack;
	TreeNode* pCurrent = root;

	//右-> 中 ->左

	while (!nodeStack.empty() || pCurrent != nullptr)
	{
		while (pCurrent != nullptr)
		{
			nodeStack.push(pCurrent);
			pCurrent = pCurrent->right;
		}

		pCurrent = nodeStack.top();
		nodeStack.pop();

		if (k == 1)
			return pCurrent->val;

		k--;
		pCurrent = pCurrent->left;
	}

	return 0;
}

int Solution::helper(TreeNode* pNode, int k)
{
	if (pNode == nullptr)
		return -1;

	int kthLargestNum = helper(pNode->right, k);
	if (kthLargestNum != -1)
		return kthLargestNum;

	if (k == 1)
		return pNode->val;

	k--;
	kthLargestNum = helper(pNode->right, k);

	return kthLargestNum;
}
