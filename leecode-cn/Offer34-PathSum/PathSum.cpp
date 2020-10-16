#include <iostream>
#include <vector>

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
	vector<vector<int>> pathSum(TreeNode* root, int sum);

private:
	void dfs(TreeNode* pNode, int sum, vector<int>& vecCurrentPath, vector<vector<int>>& vecResult);
};

int main()
{
	Solution s;
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

	int sum = 22;

	vector<vector<int>> vecResult = s.pathSum(nullptr, sum);
	cout << vecResult.size();

	return 0;
}

vector<vector<int>> Solution::pathSum(TreeNode* root, int sum)
{
	vector<vector<int>> vecResult;
	if (root == nullptr)
		vecResult;

	vector<int> vecTemp;

	dfs(root, sum, vecTemp, vecResult);

	return vecResult;
}

void Solution::dfs(TreeNode* pNode, int sum, vector<int>& vecCurrentPath, vector<vector<int>>& vecResult)
{
	if (sum - pNode->val == 0)
	{
		if (pNode->left == nullptr && pNode->right == nullptr)
		{
			vector<int>* vec = new vector<int>();
			for (int val : vecCurrentPath)
				vec->push_back(val);

			vec->push_back(pNode->val);

			vecResult.push_back(*vec);
			return;
		}


	}

	vecCurrentPath.push_back(pNode->val);

	if (pNode->left)
		dfs(pNode->left, sum - pNode->val, vecCurrentPath, vecResult);

	if (pNode->right)
		dfs(pNode->right, sum - pNode->val, vecCurrentPath, vecResult);

	vecCurrentPath.pop_back();
}