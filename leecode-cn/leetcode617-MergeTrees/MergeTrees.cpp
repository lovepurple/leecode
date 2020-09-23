#include <iostream>

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
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2);
};

int main()
{
	TreeNode* pTree1Root = new TreeNode(1);
	TreeNode* pTree1Node1 = new TreeNode(3);
	TreeNode* pTree1Node2 = new TreeNode(2);
	TreeNode* pTree1Node3 = new TreeNode(5);
	
	pTree1Node1->left = pTree1Node3;
	pTree1Root->left = pTree1Node1;
	pTree1Root->right = pTree1Node2;

	TreeNode* pTree2Root = new TreeNode(2);
	TreeNode* pTree2Node1 = new TreeNode(1);
	TreeNode* pTree2Node2 = new TreeNode(3);
	TreeNode* pTree2Node3 = new TreeNode(4);
	TreeNode* pTree2Node4 = new TreeNode(7);
	
	pTree2Root->left = pTree2Node1;
	pTree2Root->right = pTree2Node2;
	pTree2Node1->right = pTree2Node3;
	pTree2Node2->right = pTree2Node4;

	Solution s;
	TreeNode* pMerged = s.mergeTrees(pTree1Root, pTree2Root);
	cout << pMerged;

	return 0;
}

TreeNode* Solution::mergeTrees(TreeNode* t1, TreeNode* t2)
{
	if (t1 == nullptr && t2 == nullptr)
		return nullptr;

	if (t2 == nullptr)
		return t1;

	if (t1 == nullptr)
		return t2;

	t1->val = t1->val + t2->val;

	t1->left = mergeTrees(t1->left, t2->left);
	t1->right = mergeTrees(t1->right, t2->right);

	return t1;
}
