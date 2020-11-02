#include <iostream>
#include <vector>
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
	int sumNumbers(TreeNode* root);

	int sumNumbersNonRecursion(TreeNode* root);

	void dfs(TreeNode* pNode, vector<int>& vecVal, int& result);
};

int main()
{
	TreeNode* pRootNode = new TreeNode(4);
	pRootNode->left = new TreeNode(9);
	pRootNode->right = new TreeNode(0);
	pRootNode->left->left = new TreeNode(5);
	pRootNode->left->right = new TreeNode(1);

	Solution s;
	int sum = s.sumNumbersNonRecursion(pRootNode);

	std::cout << sum;

	return 0;
}

int Solution::sumNumbers(TreeNode* root)
{
	int result = 0;
	if (root == nullptr)
		return result;

	vector<int> vecVal;

	dfs(root, vecVal, result);

	return result;
}

int Solution::sumNumbersNonRecursion(TreeNode* root)
{
	/*stack<TreeNode*> nodeStack;
	TreeNode* pCurrent = root;
	int result = 0;
	vector<int> vecNumElement;

	while (!nodeStack.empty() || pCurrent != nullptr)
	{
		while (pCurrent != nullptr)
		{
			nodeStack.push(pCurrent);
			vecNumElement.push_back(pCurrent->val);
			pCurrent = pCurrent->left;
		}

		pCurrent = nodeStack.top();
		nodeStack.pop();

		if (pCurrent->right == nullptr)
		{
			int val = 0;
			for (int i = 0; i < vecNumElement.size(); ++i)
				val = val * 10 + vecNumElement[i];
			  
			result += val;

			vecNumElement.pop_back();
		}

		pCurrent = pCurrent->right;

	}

	return result;*/
}

void Solution::dfs(TreeNode* pNode, vector<int>& vecVal, int& result)
{
	if (!pNode->left && !pNode->right)
	{
		int val = 0;
		for (int i = 0; i < vecVal.size(); ++i)
			val = val * 10 + vecVal[i];

		val = val * 10 + pNode->val;

		result += val;

		return;
	}

	vecVal.push_back(pNode->val);

	if (pNode->left)
		dfs(pNode->left, vecVal, result);

	if (pNode->right)
		dfs(pNode->right, vecVal, result);

	vecVal.pop_back();
}
