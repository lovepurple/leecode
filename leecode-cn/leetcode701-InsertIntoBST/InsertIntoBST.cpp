#include <iostream>

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
	TreeNode* insertIntoBST(TreeNode* root, int val);

	//TreeNode* insertElement(TreeNode* pParentNode,TreeNode* pNex)
};


int main()
{
	TreeNode* pRoot = new TreeNode(4);
	pRoot->left = new TreeNode(2);
	pRoot->right = new TreeNode(7);

	pRoot->left->left = new TreeNode(1);
	pRoot->left->right = new TreeNode(3);

	int insertVal = 5;
	Solution s;

	TreeNode* r = s.insertIntoBST(pRoot, insertVal);
	cout << r;

	//cout << vecRes.size();

	return 0;
}

TreeNode* Solution::insertIntoBST(TreeNode* root, int val)
{
	if (root == nullptr)
		return new TreeNode(val);

	TreeNode* pNextNode = nullptr;
	if (val >= root->val)
		pNextNode = root->right;
	else
		pNextNode = root->left;

	if (pNextNode != nullptr)
		insertIntoBST(pNextNode, val);
	else
	{
		TreeNode* pValNode = new TreeNode(val);
		if (val >= root->val)
			root->right = pValNode;
		else
			root->left = pValNode;
	}


	return root;
}
