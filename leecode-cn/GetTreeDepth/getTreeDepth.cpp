/*
	递归练习，返回数的深度
*/
#include <iostream>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};



int getTreeDepth(TreeNode* rootNode)
{
	int depth = 0;

	TreeNode* pTreeNode = rootNode;
	while (pTreeNode != NULL)
	{
		depth++;
		pTreeNode = pTreeNode->left;


	}
	return 0;
}

/*
	递归求解的理解：
*/
int getTreeDepthRecursion(TreeNode* rootNode)
{
	if (rootNode == NULL)
		return 0;

	int leftDepth = getTreeDepthRecursion(rootNode->left);
	int rightDepth = getTreeDepthRecursion(rootNode->right);

	if (leftDepth > rightDepth)
		return leftDepth + 1;
	else
		return rightDepth + 1;

}
int main()
{
	/*
					1
				   / \
				  2   3
				 /   / \
				4   5   6
					 \  /
					  7 8
	*/

	TreeNode* pRoot = new TreeNode(1);
	pRoot->left = new TreeNode(2);
	pRoot->right = new TreeNode(3);

	pRoot->left->left = new TreeNode(4);

	pRoot->right->left = new TreeNode(5);
	pRoot->right->right = new TreeNode(6);
	pRoot->right->left->right = new TreeNode(7);
	pRoot->right->right->left = new TreeNode(8);

	std::cout << "TreeDepth:" << getTreeDepthRecursion(pRoot);


	return 0;
}