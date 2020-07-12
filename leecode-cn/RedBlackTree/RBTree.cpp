#include "RBTree.h"
#include <vector>

RBTreeNode* RBTree::insert(RBTreeNode* pInsertNode)
{
	if (this->pRootNode == nullptr)
	{
		pRootNode = pInsertNode;
		pRootNode->eNodeType = E_RBTreeNodeType::BLACK;
	}



	return pRootNode;
}

RBTreeNode* RBTree::insert(int insertVal)
{
	RBTreeNode* pInsterNode = new RBTreeNode(insertVal);
	insert(pInsterNode);
}

RBTreeNode* RBTree::search(int findValue)
{
	RBTreeNode* pTempSearchNode = pRootNode;
	if (pTempSearchNode == nullptr)
		return nullptr;

	while (pTempSearchNode != nullptr)
	{
		if (pTempSearchNode->nodeValue > findValue)
			pTempSearchNode = pTempSearchNode->pLeftNode;
		else if (pTempSearchNode->nodeValue < findValue)
			pTempSearchNode = pRootNode->pRightNode;
		else
			return pTempSearchNode;
	}

	return nullptr;
}

RBTreeNode* RBTree::searchParent(int searchValue)
{
	RBTreeNode* pSearchNode = search(searchValue);

	return pSearchNode ? pSearchNode->pParentNode : nullptr;
}

/// <summary>
/// 非递归中序遍历二叉树
/// </summary>
void RBTree::printTreeLNR()
{
	std::vector<RBTreeNode*> tempNodeStack;

	RBTreeNode* pCurrentNode = pRootNode;

	while (tempNodeStack.size() > 0 || pCurrentNode != nullptr)
	{
		

	}


}

void RBTree::printTreeNLR()
{
}

void RBTree::printTreeLRN()
{
}
