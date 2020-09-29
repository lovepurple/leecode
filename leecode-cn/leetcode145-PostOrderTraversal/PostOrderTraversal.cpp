#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};


class Solution
{
public:
	vector<int> postorderTraversal(TreeNode* root);
};

vector<int> Solution::postorderTraversal(TreeNode* root)
{
	vector<int> vecPostOrder;
	if (root == nullptr)
		return vecPostOrder;

	stack<TreeNode*> nodeStack;
	TreeNode* pCurrent = root;
	TreeNode* pLastVisitedNode = nullptr;

	while (!nodeStack.empty() || pCurrent != nullptr)
	{
		while (pCurrent != nullptr)
		{
			nodeStack.push(pCurrent);
			pCurrent = pCurrent->left;
		}


		pCurrent = nodeStack.top();

		//多练习 模板法
		if (pCurrent->right == nullptr || pCurrent->right == pLastVisitedNode)
		{
			vecPostOrder.push_back(pCurrent->val);
			nodeStack.pop();
			pLastVisitedNode = pCurrent;			//上次访问的和当前节点一定是前后关系
			pCurrent = nullptr;			//一定要置空，从栈中拿上级元素
		}
		else
		{
			pCurrent = pCurrent->right;
		}
	}

	return vecPostOrder;
}
