#include <iostream>

struct TreeNode
{
	int val;
	TreeNode* pLeft;
	TreeNode* pRight;
};

class Tree
{
public:
	Tree(TreeNode* rootNode) :pRoot(rootNode) {}
	~Tree();

	TreeNode* leftRotate(TreeNode* rotateNode);

	TreeNode* rightRotate(TreeNode* rotateNode);

	/// <summary>
	/// 中序打印
	/// </summary>
	void printTreeLNR(TreeNode* rootNode);

	void printTreeLNR();

	/// <summary>
	/// 前序打印
	/// </summary>
	/// <param name="rootNode"></param>
	void printTreeNLR(TreeNode* rootNode);


	void priteTreeNLR();


	TreeNode* findParentNode(TreeNode* node);

	TreeNode* findParentNode(int nodeValue);

	TreeNode* findNode(int nodeValue);


	TreeNode* pRoot;
};

Tree::~Tree()
{
	delete pRoot;
}

TreeNode* Tree::leftRotate(TreeNode* rotateNode)
{
	if (rotateNode == pRoot)
		return pRoot;

	TreeNode* pOldParent = findParentNode(rotateNode);
	if (pOldParent == nullptr)
	{
		 
	}

	TreeNode* pRightChild = rotateNode->pRight;
	rotateNode->pRight = pRightChild->pLeft;
	pRightChild->pLeft = rotateNode;

	pOldParent->pLeft = pRightChild;

	return pRoot;
}

TreeNode* Tree::rightRotate(TreeNode* rotateNode)
{
	//右旋，父变右子，右子变左孙
	if (rotateNode == pRoot)
		return pRoot;

	/*
				1
			   / \
			  0   3
				 / \
				2   4
	*/

	TreeNode* pOldParent = findParentNode(rotateNode);
	if (pOldParent == nullptr)
	{
		if (rotateNode->pLeft == nullptr)
			return pRoot;

		pOldParent = rotateNode->pLeft;
	}

	pOldParent->pLeft = rotateNode->pRight;
	rotateNode->pRight = pOldParent;

	if (pOldParent == pRoot)
		pRoot = rotateNode;
	else
	{
		TreeNode* pParentParentNode = findParentNode(pOldParent);
		pParentParentNode->pLeft = rotateNode;
	}

	return pRoot;
}

//理解。。。理解 。。。。。
void Tree::printTreeLNR(TreeNode* rootNode)
{
	if (rootNode != NULL)
	{
		if (rootNode->pLeft != NULL)
			printTreeLNR(rootNode->pLeft);

		std::cout << rootNode->val << "->";

		if (rootNode->pRight != NULL)
			printTreeLNR(rootNode->pRight);
	}


}

void Tree::printTreeLNR()
{
	printTreeLNR(this->pRoot);
}

void Tree::printTreeNLR(TreeNode* rootNode)
{
	if (rootNode != NULL)
	{
		std::cout << rootNode->val << "->";

		if (rootNode->pLeft != NULL)
			printTreeNLR(rootNode->pLeft);

		if (rootNode->pRight != NULL)
			printTreeNLR(rootNode->pRight);
	}
}

void Tree::priteTreeNLR()
{
	printTreeNLR(this->pRoot);
}

TreeNode* Tree::findParentNode(TreeNode* node)
{
	if (node == pRoot)
		return pRoot;

	TreeNode* pParentNode = nullptr;
	TreeNode* pTempNode = pRoot;
	while (pTempNode != NULL)
	{
		if (pTempNode->val > node->val)
		{
			pParentNode = pTempNode;
			pTempNode = pParentNode->pLeft;
		}
		else if (pTempNode->val < node->val)
		{
			pParentNode = pTempNode;
			pTempNode = pParentNode->pRight;
		}
		else
			return pParentNode;
	}

	return pParentNode;
}

TreeNode* Tree::findParentNode(int nodeValue)
{
	if (nodeValue == pRoot->val)
		return pRoot;

	TreeNode* pParentNode = nullptr;
	TreeNode* pTempNode = pRoot;
	while (pTempNode != NULL)
	{
		if (pTempNode->val > nodeValue)
		{
			pParentNode = pTempNode;
			pTempNode = pParentNode->pLeft;
		}
		else if (pTempNode->val < nodeValue)
		{
			pParentNode = pTempNode;
			pTempNode = pParentNode->pRight;
		}
		else
			return pParentNode;
	}

	return pParentNode;
}

TreeNode* Tree::findNode(int nodeValue)
{
	TreeNode* tempNode = pRoot;
	while (tempNode != nullptr)
	{
		if (tempNode->val < nodeValue)
			tempNode = tempNode->pRight;
		else if (tempNode->val > nodeValue)
			tempNode = tempNode->pLeft;
		else
			return tempNode;
	}

	return nullptr;
}

int main()
{
	//构造二叉树

	TreeNode* pRootNode = new TreeNode();
	pRootNode->val = 5;
	pRootNode->pLeft = new TreeNode();
	pRootNode->pLeft->val = 3;
	pRootNode->pLeft->pLeft = new TreeNode();
	pRootNode->pLeft->pLeft->val = 1;
	pRootNode->pLeft->pRight = new TreeNode();
	pRootNode->pLeft->pRight->val = 4;
	pRootNode->pLeft->pRight->pLeft = NULL;
	pRootNode->pLeft->pRight->pRight = NULL;


	pRootNode->pRight = new TreeNode();
	pRootNode->pRight->val = 9;
	pRootNode->pRight->pRight = NULL;

	pRootNode->pRight->pLeft = new TreeNode();
	pRootNode->pRight->pLeft->val = 7;
	pRootNode->pRight->pLeft->pLeft = new TreeNode();
	pRootNode->pRight->pLeft->pLeft->val = 6;
	pRootNode->pRight->pLeft->pLeft->pLeft = NULL;
	pRootNode->pRight->pLeft->pLeft->pRight = NULL;

	pRootNode->pRight->pLeft->pRight = new TreeNode();
	pRootNode->pRight->pLeft->pRight->val = 8;
	pRootNode->pRight->pLeft->pRight->pLeft = NULL;
	pRootNode->pRight->pLeft->pRight->pRight = NULL;

	pRootNode->pLeft->pLeft->pLeft = new TreeNode();
	pRootNode->pLeft->pLeft->pLeft->val = 0;
	pRootNode->pLeft->pLeft->pLeft->pLeft = NULL;
	pRootNode->pLeft->pLeft->pLeft->pRight = NULL;

	pRootNode->pLeft->pLeft->pRight = new TreeNode();
	pRootNode->pLeft->pLeft->pRight->val = 2;
	pRootNode->pLeft->pLeft->pRight->pLeft = NULL;
	pRootNode->pLeft->pLeft->pRight->pRight = NULL;


	Tree tree(pRootNode);
	//tree.printTreeLNR(pRootNode);			//节点旋转 中序遍历的结果不变
	std::cout << "-----------" << std::endl;
	tree.printTreeLNR(pRootNode);
	std::cout << "-----------" << std::endl;

	TreeNode* pRoateNode = tree.findNode(1);
	if (pRoateNode != nullptr)
	{
		tree.rightRotate(pRoateNode);
		tree.printTreeLNR(tree.pRoot);

		std::cout << std::endl;
		tree.leftRotate(pRoateNode);
		tree.printTreeLNR(tree.pRoot);

		//std::cout << "-----------" << std::endl;

		//tree.rightRotate(pRoateNode);
		//tree.printTreeNLR(tree.pRoot);
		////std::cout << "-----------" << std::endl;

	}


	system("pause");
	return 1;
}
