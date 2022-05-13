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


bool isSymetricInternal(TreeNode* pNode1, TreeNode* pNode2)
{
	if (pNode1 == nullptr && pNode2 != nullptr)
		return false;

	if (pNode2 == nullptr && pNode1 != nullptr)
		return false;

	if (pNode1 == nullptr && pNode2 == nullptr)
		return true;

	bool isSame = pNode1->val == pNode2->val;

	bool isSyetric = isSame && isSymetricInternal(pNode1->left, pNode2->right) && isSymetricInternal(pNode1->right, pNode2->left);

	return isSyetric;
}

bool isSymetric(TreeNode* root)
{
	if (root == nullptr)
		return true;

	return isSymetricInternal(root->left, root->right);
}

int main()
{
	TreeNode* pRoot = new TreeNode(1);
	pRoot->left = new TreeNode(2);
	pRoot->right = new TreeNode(2);

	pRoot->left->left = new TreeNode(3);
	pRoot->left->right = new TreeNode(3);

	pRoot->right->left = new TreeNode(3);
	pRoot->right->right = new TreeNode(3);

	cout << isSymetric(pRoot);

	return 0;
}