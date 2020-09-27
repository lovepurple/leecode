#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
};

int main()
{
	ListNode* pL1 = new ListNode(1);
	pL1->next = new ListNode(2);
	pL1->next->next = new ListNode(4);

	ListNode* pL2 = new ListNode(1);
	pL2->next = new ListNode(3);
	pL2->next->next = new ListNode(4);

	Solution s;
	ListNode* pMergedHead = s.mergeTwoLists(pL1, pL2);
	std::cout << pMergedHead;

	return 0;
}

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if (l1 == nullptr || l2 == nullptr)
	{
		if (l1 == nullptr && l2 == nullptr)
			return nullptr;

		if (l1 != nullptr)
			return l1;

		if (l2 != nullptr)
			return l2;
	}

	ListNode* pHead = nullptr;
	if (l1->val < l2->val)
	{
		pHead = l1;
		l1 = l1->next;
	}
	else
	{
		pHead = l2;
		l2 = l2->next;
	}

	ListNode* pCurrent = pHead;


	while (l1 != nullptr || l2 != nullptr)
	{
	
		if (l1 == nullptr)
		{
			pCurrent->next = l2;
			break;
		}
		else if (l2 == nullptr)
		{
			pCurrent->next = l1;
			break;
		}
		else
		{
			if (l1->val < l2->val)
			{
				pCurrent->next = l1;
				l1 = l1->next;
			}
			else
			{
				pCurrent->next = l2;
				l2 = l2->next;
			}
			pCurrent = pCurrent->next;
		}
	}

	return pHead;
}
