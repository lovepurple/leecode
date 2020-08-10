/*
	判断两个二叉树是否相同

	二叉树的遍历
		前序 中序 后序 都行，

			1
		   / \
		  2   3
		   \   \
			4   5
			   / \
			  6   7
*/
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	bool isSameTree(TreeNode* p, TreeNode* q);

	void travelTreeMidOrder(TreeNode* p);

	void travelTreePreOrder(TreeNode* p);

	void travelTreePostOrder(TreeNode* p);
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

	//node5->left = node6;
	//node5->right = node7;
	//node3->right = node5;
	//node2->right = node4;
	//root->left = node2;
	//root->right = node2;

	/*s.travelTreeMidOrder(root);
	cout << endl;
	s.travelTreePreOrder(root);
	cout << endl;
	s.travelTreePostOrder(root);
*/
	root = nullptr;




	TreeNode* root2 = nullptr;
	//TreeNode* root2Node = new TreeNode(2);
	//TreeNode* root2Node1 = new TreeNode(3);

	//root2->left = nullptr;
	//root2->right = root2Node;

	cout << s.isSameTree(root, root2);

	return 0;
}

bool Solution::isSameTree(TreeNode* p, TreeNode* q)
{
	stack<TreeNode*> leftStack;
	TreeNode* lastVisitiedLeft = nullptr;

	stack<TreeNode*> rightStack;
	TreeNode* lastVisitedRight = nullptr;

	if ((p == nullptr || q == nullptr) && p != q)
		return false;

	//if (p->val != q->val)
	//	return false;


	//使用后序遍历判断树是否相同
	while ((p != nullptr || !leftStack.empty()) && ((q != nullptr || !rightStack.empty())))
	{
		while (p != nullptr || q != nullptr)
		{
			//p q如果不同步
			if (p == nullptr || q == nullptr && p != q)
				return false;

			if (p->val != q->val)
				return false;

			leftStack.push(p);
			p = p->left;

			rightStack.push(q);
			q = q->left;
		}

		p = leftStack.top();
		q = rightStack.top();

		if (p->val != q->val)
			return false;

		//当前的节点是叶子点或叶子点已经访问过
		if ((p->right == nullptr || p->right == lastVisitiedLeft) && (q->right == nullptr || q->right == lastVisitedRight))
		{
			if (p->val != q->val)
				return false;

			leftStack.pop();
			lastVisitiedLeft = p;

			rightStack.pop();
			lastVisitedRight = q;

			p = nullptr;
			q = nullptr;
		}
		else
		{
			p = p->right;
			q = q->right;
		}
	}

	return true;
}

void Solution::travelTreeMidOrder(TreeNode* p)
{
	stack<TreeNode*> treeNodeStack;
	TreeNode* pCurrent = p;

	while (pCurrent != NULL || !treeNodeStack.empty())
	{
		while (pCurrent != nullptr)
		{
			treeNodeStack.push(pCurrent);
			pCurrent = pCurrent->left;
		}

		pCurrent = treeNodeStack.top();
		treeNodeStack.pop();

		cout << pCurrent->val << "->";
		pCurrent = pCurrent->right;

	}
}

void Solution::travelTreePreOrder(TreeNode* p)
{
	stack<TreeNode*> treeNodeStack;
	TreeNode* pCurrent = p;
	while (pCurrent != NULL || !treeNodeStack.empty())
	{
		//中序时，只要有左子树 可直接输出
		while (pCurrent != nullptr)
		{
			cout << pCurrent->val << "->";
			treeNodeStack.push(pCurrent);
			pCurrent = pCurrent->left;
		}

		//直接出栈的就是中间
		pCurrent = treeNodeStack.top();
		treeNodeStack.pop();

		pCurrent = pCurrent->right;

	}
}

/// <summary>
/// 后续遍历有一个不一样的点 左-》右-》中 需要记录上一个点是否访问过
/// </summary>
/// <param name="p"></param>
/// 模板法  前 中 后都能用这个模板（多练习）
/// 不管哪种顺序
void Solution::travelTreePostOrder(TreeNode* p)
{
	stack<TreeNode*> treeNodeStack;
	TreeNode* pCurrent = p;
	TreeNode* pLastVisited = NULL;

	while (pCurrent != nullptr || !treeNodeStack.empty())
	{
		//先找到每个子树的最左(wget)
		while (pCurrent != nullptr)
		{
			treeNodeStack.push(pCurrent);
			pCurrent = pCurrent->left;
		}

		pCurrent = treeNodeStack.top();		//不能直接pop()还需要用到 当前节点是middle

		if (pCurrent->right == nullptr || pCurrent->right == pLastVisited)			//当前节点有可能是从右子树回溯的
		{
			cout << pCurrent->val << "->";
			pLastVisited = pCurrent;
			treeNodeStack.pop();			//子树已经为空
			pCurrent = nullptr;
		}
		else    //右子树还有节点
		{
			pCurrent = pCurrent->right;
		}



	}
}
