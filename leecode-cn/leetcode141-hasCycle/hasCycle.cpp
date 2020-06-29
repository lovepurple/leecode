/*
	双指针判断链表是否有环
*/
#include <iostream>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution
{
public:
	bool hasCycle(ListNode* head);

};

int main()
{
	ListNode* p0 = new ListNode(3);
	ListNode* p1 = new ListNode(2);
	ListNode* p2 = new ListNode(0);
	ListNode* p3 = new ListNode(-4);

	p0->next = p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = p1;

	Solution solution;
	std::cout << solution.hasCycle(p0) << std::endl;


	system("pause");
	return 0;
}

bool Solution::hasCycle(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return false;

	//快慢指针，如果有环，快指针还能追上慢指针
	ListNode* pFast = head;
	ListNode* pSlow = head;

	while (pFast != nullptr)
	{
		if (pFast->next != nullptr)
			pFast = pFast->next->next;
		else
			return false;

		pFast = pFast->next->next;
		pSlow = pSlow->next;

		if (pFast == pSlow)
			return true;
	}

	return false;
}
