/*
	线索二叉树，将二叉树变成双向链表
*/
#include <iostream>
/*
	二叉树 线索化，可实现 结点的双向查找
*/

/// <summary>
/// 节点对象，在正常的二叉树节点基础上标记左右指针是否是链表指针
/// </summary>
struct TBTreeNode
{
	int val;
	TBTreeNode* pLeft;
	TBTreeNode* pRight;
	bool isLeftThread;
	bool isRightThread;
	TBTreeNode(int x) : val(x), pLeft(NULL), pRight(NULL), isRightThread(false), isLeftThread(false) {}
};

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class ThreadBinaryTree
{
public:
	static TBTreeNode* BuildMiddleOrderThreadBinaryTree(ThreadBinaryTree* pBinaryTreeRoot);

	void inorderMorrisTraversal(TreeNode* root);
};

int main()
{
	TreeNode* pRootNode = new TreeNode(6);
	TreeNode* pNode1 = new TreeNode(2);
	TreeNode* pNode2 = new TreeNode(7);
	TreeNode* pNode3 = new TreeNode(1);
	TreeNode* pNode4 = new TreeNode(4);
	TreeNode* pNode5 = new TreeNode(9);
	TreeNode* pNode6 = new TreeNode(3);
	TreeNode* pNode7 = new TreeNode(5);
	TreeNode* pNode8 = new TreeNode(8);

	pNode4->left = pNode6;
	pNode4->right = pNode7;

	pNode2->right = pNode5;

	pNode5->left = pNode8;

	pNode1->left = pNode3;
	pNode1->right = pNode4;

	pRootNode->left = pNode1;
	pRootNode->right = pNode2;

	ThreadBinaryTree instance;
	instance.inorderMorrisTraversal(pRootNode);


	return 0;
}

TBTreeNode* ThreadBinaryTree::BuildMiddleOrderThreadBinaryTree(ThreadBinaryTree* pBinaryTreeRoot)
{
	return nullptr;
}

void ThreadBinaryTree::inorderMorrisTraversal(TreeNode* root)
{
	TreeNode* cur = root, * pMostRight = NULL;
	while (cur != NULL)
	{
		if (cur->left == NULL)          // 1.
		{
			std::cout << cur->val << "->";
			cur = cur->right;
		}
		else
		{
			pMostRight = cur->left;
			while (pMostRight->right != NULL && pMostRight->right != cur)
				pMostRight = pMostRight->right;

			if (pMostRight->right == NULL)   // 2.a)
			{
				pMostRight->right = cur;
				cur = cur->left;
			}
			else                       // 2.b)
			{
				pMostRight->right = NULL;
				std::cout << cur->val << "->";
				cur = cur->right;
			}
		}
	}
}
