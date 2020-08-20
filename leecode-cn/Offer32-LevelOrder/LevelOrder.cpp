/*
	按层次输出二叉树（广度优先 遍历）
*/
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

class Solution
{
public:
	vector<vector<int>> levelOrder(TreeNode* root);


};

int main()
{
	Solution s;

	TreeNode* pRoot = new TreeNode(3);
	TreeNode* pL10 = new TreeNode(9);
	TreeNode* pL11 = new TreeNode(20);
	TreeNode* pL23 = new TreeNode(15);
	TreeNode* pL24 = new TreeNode(7);

	pRoot->left = pL10;
	pRoot->right = pL11;
	pL11->left = pL23;
	pL11->right = pL24;

	vector<vector<int>> result = s.levelOrder(pRoot);

	cout << 1;

	return 0;
}

vector<vector<int>> Solution::levelOrder(TreeNode* root)
{
	vector<vector<int>> result;
	if (root == nullptr)
		return result;

	queue<TreeNode*> levelNodeQueue;
	levelNodeQueue.push(root);

	queue<TreeNode*> nextLevelNodeQueue;

	while (!levelNodeQueue.empty() || !nextLevelNodeQueue.empty())
	{
		//由于要求每一层按一个数组，使用另一个队列控制每一层
		if (levelNodeQueue.empty())
		{
			while (!nextLevelNodeQueue.empty())
			{
				levelNodeQueue.push(nextLevelNodeQueue.front());
				nextLevelNodeQueue.pop();
			}
		}

		vector<int> levelResult;

		while (!levelNodeQueue.empty())
		{
			TreeNode* pNode = levelNodeQueue.front();
			levelNodeQueue.pop();
			levelResult.push_back(pNode->val);

			if (pNode->left)
				nextLevelNodeQueue.push(pNode->left);

			if (pNode->right)
				nextLevelNodeQueue.push(pNode->right);
		}
		result.push_back(levelResult);
	}

	return result;
}
