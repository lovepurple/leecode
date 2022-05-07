#pragma once
#include <cstddef>

class TreeNode
{
public:
	TreeNode(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
	int val;
	TreeNode* left, * right;
};

