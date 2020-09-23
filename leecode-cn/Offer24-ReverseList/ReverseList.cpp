#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* reverseList(ListNode* head);

	void swap(ListNode* pNode1, ListNode* pNode2);
};


int main()
{
	ListNode* pNode0 = new ListNode(1);
	ListNode* pNode1 = new ListNode(2);
	pNode0->next = pNode1;

	ListNode* pNode2 = new ListNode(3);
	pNode1->next = pNode2;

	ListNode* pNode3 = new ListNode(4);
	pNode2->next = pNode3;

	ListNode* pNode4 = new ListNode(5);
	pNode3->next = pNode4;

	Solution s;
	ListNode* reversed = s.reverseList(pNode0);

	return 0;
}

ListNode* Solution::reverseList(ListNode* head)
{
	if (head == nullptr)
		return nullptr;

	if (head->next == nullptr)
		return head;

	ListNode* pReverseNode = reverseList(head->next);
	swap(head, pReverseNode);

	return pReverseNode;
}

void Solution::swap(ListNode* pNode1, ListNode* pNode2)
{
	if (pNode2 == nullptr)
		return;

	ListNode* pTemp = pNode2;

	while (pTemp->next != nullptr)
		pTemp = pTemp->next;

	pTemp->next = pNode1;
	pNode1->next = NULL;
}
