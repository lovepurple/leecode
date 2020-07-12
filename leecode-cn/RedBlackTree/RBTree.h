#pragma once
#include "TreePrinter.h"
#include <vector>

enum class E_RBTreeNodeType
{
	RED,
	BLACK
};


struct RBTreeNode
{
	RBTreeNode(int nodeVal) :nodeValue(nodeVal) {};

	int nodeValue;
	RBTreeNode* pLeftNode = nullptr;
	RBTreeNode* pRightNode = nullptr;
	RBTreeNode* pParentNode = nullptr;

	E_RBTreeNodeType eNodeType = E_RBTreeNodeType::RED;
};


class RBTree :public TreePrinter
{
public:
	RBTreeNode* insert(RBTreeNode* pInsertNode);

	RBTreeNode* insert(int insertVal);

	RBTreeNode* deleteNode(int deleteVal);

	RBTreeNode* deleteNode(RBTreeNode* pDeleteNode);

	RBTreeNode* search(int findValue);

	RBTree(std::vector<int>& arrays);



private:
	/// <summary>
	/// ½Úµã×óÐý
	/// </summary>
	/// <param name="pRotateNode"></param>
	/// <returns></returns>
	RBTreeNode* leftRotate(RBTreeNode* pRotateNode);

	/// <summary>
	/// ½ÚµãÓÒÐý
	/// </summary>
	/// <param name="pRotateNode"></param>
	/// <returns></returns>
	RBTreeNode* rightRoate(RBTreeNode* pRotateNode);

	RBTreeNode* pRootNode;

	/// <summary>
	/// æŸ¥æ‰¾çˆ¶èŠ‚ç‚¹
	/// </summary>
	/// <param name="searchValue"></param>
	/// <returns></returns>
	RBTreeNode* searchParent(int searchValue);

	// Inherited via TreePrinter
	virtual void printTreeLNR() override;
	virtual void printTreeNLR() override;
	virtual void printTreeLRN() override;
};

