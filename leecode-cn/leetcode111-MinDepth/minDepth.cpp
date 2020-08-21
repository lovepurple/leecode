#include <iostream>
#include <algorithm>

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
	int minDepth(TreeNode* root);
};

int main()
{
	Solution s;
	TreeNode* pRoot = new TreeNode(3);
	TreeNode* pL10 = new TreeNode(9);
	TreeNode* pL11 = new TreeNode(20);
	TreeNode* pL23 = new TreeNode(15);
	TreeNode* pL24 = new TreeNode(7);

	pRoot->left = pL10;
	pRoot->right = pL11;
	pL11->left = pL23;
	pL11->right = pL24;

	cout << s.minDepth(pRoot);
	return 0;
}

int Solution::minDepth(TreeNode* root)
{
	if (root == nullptr)
		return 0;

	if (root->left != nullptr && root->right == nullptr)
		return 1 + minDepth(root->left);

	if (root->right != nullptr && root->left == nullptr)
		return 1 + minDepth(root->right);


	return 1 + min(minDepth(root->left), minDepth(root->right));
}