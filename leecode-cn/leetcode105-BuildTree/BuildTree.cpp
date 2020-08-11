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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
};

int main()
{
	Solution s;
	vector<int> preorder = { 1,2 };
	vector<int> inorder = { 1,2 };

	TreeNode* root = s.buildTree(preorder, inorder);


	return 0;
}

TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder)
{
	if (preorder.size() == 0)
		return nullptr;

	TreeNode* root = new TreeNode(preorder[0]);

	vector<int>::iterator it;
	for (it = inorder.begin(); it != inorder.end(); it++)
	{
		if (*it == preorder[0])
			break;
	}

	preorder.erase(preorder.begin());
	vector<int> left = vector<int>(inorder.begin(), it);
	vector<int> right = vector<int>(it + 1, inorder.end());

	if (left.size() > 0)
		root->left = buildTree(preorder, left);


	if (right.size() > 0)
		root->right = buildTree(preorder, right);


	return root;
}
