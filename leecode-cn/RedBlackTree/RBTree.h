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
	/// 节点左旋
	/// </summary>
	/// <param name="pRotateNode"></param>
	/// <returns></returns>
	RBTreeNode* leftRotate(RBTreeNode* pRotateNode);

	/// <summary>
	/// 节点右旋
	/// </summary>
	/// <param name="pRotateNode"></param>
	/// <returns></returns>
	RBTreeNode* rightRoate(RBTreeNode* pRotateNode);

	RBTreeNode* pRootNode;

	/// <summary>
	/// 鏌ユ壘鐖惰妭鐐?
	/// </summary>
	/// <param name="searchValue"></param>
	/// <returns></returns>
	RBTreeNode* searchParent(int searchValue);

	// Inherited via TreePrinter
	virtual void printTreeLNR() override;
	virtual void printTreeNLR() override;
	virtual void printTreeLRN() override;
};

