#include <iostream>
#include "TreeNode.h"
using namespace std;

/// <summary>
/// 二叉搜索树的最近公共祖先
/// </summary>
/// <param name="root"></param>
/// <param name="p"></param>
/// <param name="q"></param>
/// <returns></returns>
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (p->val < root->val && q->val < root->val)
		return lowestCommonAncestor(root->left, p, q);

	if (p->val > root->val && q->val > root->val)
		return lowestCommonAncestor(root->right, p, q);

	return root;
}

int main() {
	TreeNode* root = new TreeNode(6);
	root->left = new TreeNode(2);
	root->right = new TreeNode(8);

	root->left->left = new TreeNode(0);

	root->left->right = new TreeNode(4);
	root->left->right->left = new TreeNode(3);
	root->left->right->left = new TreeNode(5);

	root->right->left = new TreeNode(8);
	root->right->left->left = new TreeNode(7);
	root->right->left->left = new TreeNode(9);

	TreeNode* pSample1 = lowestCommonAncestor(root, root->left, root->right);
	cout << pSample1->val;
	cout << std::endl;

	TreeNode* pSample2 = lowestCommonAncestor(root, root->left, root->left->right);
	cout << pSample2->val;
	cout << std::endl;

	TreeNode* pSample3 = lowestCommonAncestor(root, root->left->left, root->right->left->left);
	cout << pSample3->val;
	cout << std::endl;

	return 0;
}