#include "RBTree.h"
#include <vector>
#include <iostream>

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

RBTree::RBTree(std::vector<int>& arrays)
{
}

RBTreeNode* RBTree::leftRotate(RBTreeNode* pRotateNode)
{
	//×óĞı²»ÄÜ×ªRoot
	if (pRotateNode == pRootNode)
		return pRootNode;


	RBTreeNode* pLeftChild = pRotateNode->pLeftNode;
	RBTreeNode* pOldParent = pRotateNode->pParentNode;

	RBTreeNode* pGrandParent = pOldParent->pParentNode;

	pLeftChild->pParentNode = pOldParent;
	pOldParent->pRightNode = pLeftChild;

	pRotateNode->pLeftNode = pOldParent;
	pOldParent->pParentNode = pRotateNode;

	if (pGrandParent == nullptr)
		pRotateNode = pRootNode;
	else
	{
		pGrandParent->pLeftNode = pRotateNode;
		pRotateNode->pParentNode = pRotateNode;
	}

	return pRootNode;
}

RBTreeNode* RBTree::rightRoate(RBTreeNode* pRotateNode)
{
	RBTreeNode* pRightNode = pRotateNode->pRightNode;
	RBTreeNode* pParentNode = pRotateNode->pParentNode;



	return nullptr;
}

RBTreeNode* RBTree::searchParent(int searchValue)
{
	RBTreeNode* pSearchNode = search(searchValue);

	return pSearchNode ? pSearchNode->pParentNode : nullptr;
}

/// <summary>
/// éé€’å½’ä¸­åºéå†äºŒå‰æ ‘
/// </summary>
void RBTree::printTreeLNR()
{
	std::vector<RBTreeNode*> tempNodeStack;

	RBTreeNode* pCurrentNode = pRootNode;

	while (tempNodeStack.size() > 0 || pCurrentNode != nullptr)
	{
		//Ò»Ö±×·µ½×î×ó×ÓÊ÷
		if (pCurrentNode != nullptr)
		{
			tempNodeStack.push_back(pCurrentNode);
			pCurrentNode = pCurrentNode->pLeftNode;
		}
		else
		{
			pCurrentNode = tempNodeStack.back();
			tempNodeStack.pop_back();

			std::cout << pCurrentNode->nodeValue << "->";

			pCurrentNode = pCurrentNode->pRightNode;
		}
	}


}

void RBTree::printTreeNLR()
{
}

void RBTree::printTreeLRN()
{
}
