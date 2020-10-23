#include <iostream>

using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution
{
public:
	bool isPalindrome(ListNode* head);

	ListNode* reverseList(ListNode* pListNode);
};

int main()
{
	ListNode* pL1 = new ListNode(1);
	pL1->next = new ListNode(2);
	pL1->next->next = new ListNode(2);
	pL1->next->next->next = new ListNode(1);
	//pL1->next->next->next->next = new ListNode(1);

	Solution s;

	cout << s.isPalindrome(pL1);

	return 0;
}

bool Solution::isPalindrome(ListNode* head)
{
	if (head == nullptr)
		return true;

	ListNode* pSlow = head;
	ListNode* pFast = head;

	while (pFast != nullptr && pFast->next != nullptr)
	{
		//pSlow = pSlow->next;
		pFast = pFast->next->next;
		if (pFast)
			pSlow = pSlow->next;
	}

	ListNode* pMid = pSlow;
	pSlow = head;

	if (pMid->next == nullptr)
	{
		return pMid->val == head->val;
	}

	ListNode* pOtherSegment = reverseList(pMid->next);
	while (pSlow != nullptr && pSlow != pMid)
	{
		if (pSlow->val != pOtherSegment->val)
			return false;

		pSlow = pSlow->next;
		pOtherSegment = pOtherSegment->next;
	}

	if (pOtherSegment != nullptr)
		return pMid->val == pOtherSegment->val;

	return true;
}

ListNode* Solution::reverseList(ListNode* pListNode)
{
	if (pListNode == nullptr)
		return pListNode;

	if (pListNode->next == nullptr)
		return pListNode;

	ListNode* pNode = reverseList(pListNode->next);

	ListNode* pTemp = pNode;
	while (pTemp->next != nullptr)
		pTemp = pTemp->next;

	pTemp->next = pListNode;
	pListNode->next = nullptr;

	return pNode;
}
