#include <iostream>
#include <queue>
#include <stack>

using namespace std;
/*
	判断B子树是否是A树的一部分，
	 二叉树中序遍历
		2 3 2 1
		3 null 2 2  使用中序就有问题。。。。

*/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	bool isSubStructure(TreeNode* A, TreeNode* B);


};

int main()
{

	Solution s;
	TreeNode* pRoot = new TreeNode(2);
	TreeNode* pL10 = new TreeNode(3);
	TreeNode* pL11 = new TreeNode(2);
	TreeNode* pL23 = new TreeNode(1);
	//TreeNode* pL24 = new TreeNode(7);

	pRoot->left = pL10;
	pRoot->right = pL11;
	pL10->left = pL23;


	TreeNode* pRootB = new TreeNode(3);
	TreeNode* pRooBL10 = new TreeNode(2);
	TreeNode* pRooBL20 = new TreeNode(2);
	pRootB->right = pRooBL10;
	pRooBL10->left = pRooBL20;

	cout << s.isSubStructure(pRoot, pRootB);

	return 0;
}

bool Solution::isSubStructure(TreeNode* A, TreeNode* B)
{
	 
}



 