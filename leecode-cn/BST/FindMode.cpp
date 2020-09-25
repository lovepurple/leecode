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

	/// <summary>
	/// leetcode501 获取二叉搜索树中的众数列表，中序遍历的顺序就是
	/// </summary>
	/// <param name="root"></param>
	/// <returns></returns>
	vector<int>findMode(TreeNode* root);

	/// <summary>
	/// 中序非递归遍历(反复练习)
	/// </summary>
	/// <param name="root"></param>
	void TravelMidOrder(TreeNode* root);
};

int main()
{
	TreeNode* pRootNode = new TreeNode(5);
	TreeNode* pNode1 = new TreeNode(4);
	TreeNode* pNode2 = new TreeNode(16);
	TreeNode* pNode3 = new TreeNode(2);
	TreeNode* pNode4 = new TreeNode(10);
	TreeNode* pNode5 = new TreeNode(20);
	TreeNode* pNode6 = new TreeNode(7);
	TreeNode* pNode7 = new TreeNode(14);
	TreeNode* pNode8 = new TreeNode(12);
	TreeNode* pNode9 = new TreeNode(15);

	pNode7->left = pNode8;
	pNode7->right = pNode9;

	pNode4->left = pNode6;
	pNode4->right = pNode7;

	pNode2->left = pNode4;
	pNode2->right = pNode5;

	pNode1->left = pNode3;

	pRootNode->left = pNode1;
	pRootNode->right = pNode2;

	Solution s;
	s.TravelMidOrder(pRootNode);
}


vector<int> Solution::findMode(TreeNode* root)
{
	vector<int> vecMode();



	return vector<int>();
}

void Solution::TravelMidOrder(TreeNode* root)
{
	stack<TreeNode*> treeNodeStack;
	TreeNode* pCurrentNode = root;

	while (!treeNodeStack.empty() || pCurrentNode != nullptr)
	{
		while (pCurrentNode != nullptr)
		{
			treeNodeStack.push(pCurrentNode);
			pCurrentNode = pCurrentNode->left;
		}

		pCurrentNode = treeNodeStack.top();
		cout << pCurrentNode->val << "->";
		treeNodeStack.pop();

		pCurrentNode = pCurrentNode->right;
	}


}
