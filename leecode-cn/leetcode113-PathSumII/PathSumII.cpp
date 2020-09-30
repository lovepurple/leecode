#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum);

	void dfs(TreeNode* pTreeNode, int remainSum, vector<int>& vecPathSum, vector<vector<int>>& vecResult);
};

int main()
{
	TreeNode* pRoot = new TreeNode(5);
	pRoot->left = new TreeNode(4);
	pRoot->right = new TreeNode(8);

	pRoot->left->left = new TreeNode(11);
	pRoot->left->left->left = new TreeNode(7);
	pRoot->left->left->right = new TreeNode(2);

	pRoot->right->left = new TreeNode(13);
	pRoot->right->right = new TreeNode(4);

	pRoot->right->right->left = new TreeNode(5);
	pRoot->right->right->right = new TreeNode(1);

	//TreeNode* pRoot = new TreeNode(-2);
	//pRoot->right = new TreeNode(-3);

	int sum = 22;
	Solution s;
	vector<vector<int>> vecRes = s.pathSum(pRoot, sum);
	cout << vecRes.size();

	return 0;
}

vector<vector<int>> Solution::pathSum(TreeNode* root, int sum)
{
	vector<vector<int>> vecResult = vector<vector<int>>();
	if (root == nullptr)
		return vecResult;

	vector<int> pathResult = vector<int>();
	dfs(root, sum, pathResult, vecResult);

	return vecResult;
}

void Solution::dfs(TreeNode* pTreeNode, int remainSum, vector<int>& vecPathSum, vector<vector<int>>& vecResult)
{
	//有可能sum就是 < 0
	/*	if (remainSum - pTreeNode->val < 0)
			return;
		else*/ if (remainSum - pTreeNode->val == 0 && pTreeNode->left == nullptr && pTreeNode->right == nullptr)
		{
			vector<int>* vecSubResult = new vector<int>();
			for (int i : vecPathSum)
				vecSubResult->push_back(i);

			vecSubResult->push_back(pTreeNode->val);

			vecResult.push_back(*vecSubResult);
		}
		else
		{
			vecPathSum.push_back(pTreeNode->val);

			if (pTreeNode->left != nullptr)
				dfs(pTreeNode->left, remainSum - pTreeNode->val, vecPathSum, vecResult);

			if (pTreeNode->right != nullptr)
				dfs(pTreeNode->right, remainSum - pTreeNode->val, vecPathSum, vecResult);

			//right结束之后表示回溯到父节点，将当前节点退回
			vecPathSum.pop_back();
		}
}
