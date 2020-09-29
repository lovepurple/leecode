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

	void dfs(TreeNode* pTreeNode, int remainSum, vector<vector<int>>& vecResult);
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

	pRoot->right->right->left = new TreeNode(4);
	pRoot->right->right->right = new TreeNode(1);

	Solution s;


	return 0;
}

vector<vector<int>> Solution::pathSum(TreeNode* root, int sum)
{
	return vector<vector<int>>();
}
