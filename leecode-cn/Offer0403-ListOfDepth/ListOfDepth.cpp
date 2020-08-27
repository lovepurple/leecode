#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	vector<ListNode*> listOfDepth(TreeNode* tree);

	/**
	 * 优化版，使用一个queue 空间复杂度优化
	 */
	vector<ListNode*> listOfDepthOptimized(TreeNode* tree);

	ListNode* appendList(ListNode* pRoot, ListNode* append);
};

int main()
{
	Solution s;

	TreeNode* root = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	TreeNode* node6 = new TreeNode(6);
	TreeNode* node7 = new TreeNode(7);
	TreeNode* node8 = new TreeNode(8);

	node4->left = node8;

	node3->right = node7;

	node2->left = node4;
	node2->right = node5;

	root->left = node2;
	root->right = node3;

	vector<ListNode*> res = s.listOfDepthOptimized(root);

	return 0;
}

vector<ListNode*> Solution::listOfDepth(TreeNode* tree)
{
	vector<ListNode*> depthList;

	if (tree == nullptr)
		return depthList;

	queue<TreeNode*> nodeQueue;
	queue<TreeNode*> nextLevelNode;
	nodeQueue.push(tree);

	ListNode* pCurrentLevelNode = nullptr;
	while (!nodeQueue.empty())
	{
		TreeNode* pCurrentNode = nodeQueue.front();
		nodeQueue.pop();

		ListNode node(pCurrentNode->val);

		pCurrentLevelNode = appendList(pCurrentLevelNode, &node);

		if (pCurrentNode->left != nullptr)
			nextLevelNode.push(pCurrentNode->left);

		if (pCurrentNode->right != nullptr)
			nextLevelNode.push(pCurrentNode->right);

		if (nodeQueue.empty())
		{
			nodeQueue = nextLevelNode;		//栈内存，不是并不是引用，需要把next清了 
			depthList.push_back(pCurrentLevelNode);
			nextLevelNode = queue<TreeNode*>();

			pCurrentLevelNode = nullptr;
		}
	}


	return depthList;
}

vector<ListNode*> Solution::listOfDepthOptimized(TreeNode* tree)
{
	vector<ListNode*> vecRes;
	queue<TreeNode*> treeNodeQueue;
	treeNodeQueue.push(tree);

	//Leetcode上 相对于上种方式 时间和空间复杂度大大提升
	while (!treeNodeQueue.empty())
	{
		ListNode* pLevelNode = nullptr;
		ListNode* pTempNode = nullptr;
		//当前queue中所有的都是同层次的
		int levelNodeCount = treeNodeQueue.size();
		while (levelNodeCount > 0)
		{
			TreeNode* pTreeNode = treeNodeQueue.front();
			treeNodeQueue.pop();
			ListNode* pNode = new ListNode(pTreeNode->val);
			if (pLevelNode == nullptr)
				pLevelNode = pNode;

			if (pTempNode == nullptr)
				pTempNode = pNode;
			else
			{
				pTempNode->next = pNode;
				pTempNode = pTempNode->next;
			}

			if (pTreeNode->left)
				treeNodeQueue.push(pTreeNode->left);

			if (pTreeNode->right)
				treeNodeQueue.push(pTreeNode->right);

			levelNodeCount--;
		}
		vecRes.push_back(pLevelNode);
	}

	return vecRes;
}

ListNode* Solution::appendList(ListNode* pRoot, ListNode* append)
{
	if (pRoot == nullptr)
		pRoot = append;
	else
	{
		ListNode* temp = pRoot;
		while (temp->next != nullptr)
			temp = temp->next;

		temp->next = append;
	}

	return pRoot;
}
