#include <iostream>
#include <vector>
#include <queue>

/**
 *  本例中，需要和深度层级有关，必须在递归的时候确定当前层级下，有没有元素。直接递归并不合适。
 *		与层级相关的问题一般都使用BFS ，
 *			while(!queue.empty())
 *			{
 *				每次处理一个层级
				for(i to queue.size)
				{
					queue.push(i->left)
					queue.push(i->right)
				}
			}
	 DFS使用 技巧： 在DFS时判断深度，vecResult.size() 可判断当前depth是否已遍历

		dfs(TreeNode* pNode,int depth,Vector<int> vecResult)

		// 先访问 当前节点，再递归地访问 右子树 和 左子树。
		if (depth == vecResult.size()) {   // 如果当前节点所在深度还没有出现在res里，说明在该深度下当前节点是第一个被访问的节点，因此将当前节点加入res中。
			res.add(root.val);
		}

 *
 */
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
	vector<int> rightSideView(TreeNode* root);

	//不记录深度的话，没办法判断当前层级是否已有元素
	void helper(TreeNode* pNode, vector<int>& vecResult);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="pNode"></param>
	/// <param name="depth">检测的深度</param>
	/// <param name="vecRightSideViewResult"></param>
	void dfs(TreeNode* pNode, int depth, vector<int>& vecRightSideViewResult);

	//BFS 
	void bfs(TreeNode* pNode, vector<int>& vecRightSideViewResult);

};

int main()
{
	/*
				1
			   / \
			  2   3
			 /   / \
			4   5   6
				 \
				  7
*/

	TreeNode* pRoot = new TreeNode(1);
	pRoot->left = new TreeNode(2);
	pRoot->right = new TreeNode(3);

	pRoot->left->left = new TreeNode(4);

	pRoot->right->left = new TreeNode(5);
	pRoot->right->right = new TreeNode(6);
	pRoot->right->left->right = new TreeNode(7);

	Solution s;
	vector<int> vecResult = s.rightSideView(pRoot);

	cout << vecResult.size();

	return 0;
}

vector<int> Solution::rightSideView(TreeNode* root)
{
	vector<int> vecTreeRightSideView = vector<int>();
	if (root == nullptr)
		return vecTreeRightSideView;

	//dfs(root, 0, vecTreeRightSideView);
	bfs(root, vecTreeRightSideView);

	return vecTreeRightSideView;
}

void Solution::helper(TreeNode* pNode, vector<int>& vecResult)
{
	bool rightHasValue = false;
	if (pNode->right != nullptr)
	{
		vecResult.push_back(pNode->right->val);
		rightHasValue = true;
		helper(pNode->right, vecResult);
	}

	if (pNode->left != nullptr)
	{
		if (!rightHasValue)
			vecResult.push_back(pNode->left->val);

		helper(pNode->left, vecResult);
	}
}

void Solution::dfs(TreeNode* pNode, int depth, vector<int>& vecRightSideViewResult)
{
	if (pNode == nullptr)
		return;

	//当depth = 4时， 如果vecRightSideViewResult.size() == 4 表示0 ，1，2 ，3 三层都已经有合法元素，当前层是一个新层
	if (vecRightSideViewResult.size() == depth)
		vecRightSideViewResult.push_back(pNode->val);

	//理解递归。。。。。
	depth++;
	dfs(pNode->right, depth, vecRightSideViewResult);
	dfs(pNode->left, depth, vecRightSideViewResult);
}

void Solution::bfs(TreeNode* pNode, vector<int>& vecRightSideViewResult)
{
	if (pNode == nullptr)
		return;

	queue<TreeNode*> depthQueue;
	depthQueue.push(pNode);

	while (!depthQueue.empty())
	{
		//queue中的所有结点都是同一层级
		int levelNodeCount = depthQueue.size();
		for (int i = 0; i < levelNodeCount; ++i)
		{
			TreeNode* pLevelNode = depthQueue.front();

			if (pLevelNode->left)
				depthQueue.push(pLevelNode->left);

			if (pLevelNode->right)
				depthQueue.push(pLevelNode->right);

			if (i == levelNodeCount - 1)
				vecRightSideViewResult.push_back(pLevelNode->val);

			depthQueue.pop();
		}
	}
}
