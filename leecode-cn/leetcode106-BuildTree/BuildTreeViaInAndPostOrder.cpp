#include <iostream>
#include <vector>

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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);
private:
	TreeNode* helper(vector<int>& inorder, int indexOfInOrderBegin, int indexOfInOrderEnd, vector<int>& postorder, int indexOfPostOrderBegin, int indexOfPostOrderEnd);
};

int main()
{
	vector<int> inOrder = { 9,3,15,20,7 };
	vector<int> postOrder = { 9,15,7,20,3 };
	Solution s;
	TreeNode* restoredTreeRoot = s.buildTree(inOrder, postOrder);

	cout << restoredTreeRoot << endl;
	return 0;
}

TreeNode* Solution::buildTree(vector<int>& inorder, vector<int>& postOrder)
{
	if (inorder.size() != postOrder.size())
		return nullptr;

	if (inorder.size() == 0 || postOrder.size() == 0)
		return nullptr;

	return helper(inorder, 0, inorder.size() - 1, postOrder, 0, postOrder.size() - 1);
}

TreeNode* Solution::helper(vector<int>& inorder, int indexOfInOrderBegin, int indexOfInOrderEnd, vector<int>& postorder, int indexOfPostOrderBegin, int indexOfPostOrderEnd)
{
	if (indexOfInOrderEnd - indexOfInOrderBegin < 0)
		return nullptr;

	if (indexOfPostOrderEnd - indexOfPostOrderBegin < 0)
		return nullptr;

	int nodeValue = postorder[indexOfPostOrderEnd];

	vector<int>::iterator nodeValueIterator = find(inorder.begin(), inorder.end(), nodeValue);
	int elementIndexInMiddleOrder = distance(inorder.begin(), nodeValueIterator);

	int leftTreeLength = elementIndexInMiddleOrder - indexOfInOrderBegin;

	TreeNode* pNode = new TreeNode(nodeValue);
	pNode->left = helper(inorder, indexOfInOrderBegin, elementIndexInMiddleOrder - 1, postorder, indexOfPostOrderBegin, indexOfPostOrderBegin + leftTreeLength - 1);
	pNode->right = helper(inorder, elementIndexInMiddleOrder + 1, indexOfInOrderEnd, postorder, indexOfPostOrderBegin + leftTreeLength, indexOfPostOrderEnd - 1);

	return pNode;
}
