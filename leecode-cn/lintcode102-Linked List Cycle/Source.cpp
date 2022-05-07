#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode* head)
{
	if (head == nullptr)
		return false;

	ListNode* pSlow = head;
	ListNode* pFast = head;


	while (true)
	{
		if (pFast->next == nullptr)
			return false;

		pFast = pFast->next;

		if (pFast->next == nullptr)
			return false;

		pFast = pFast->next;

		if (pFast->val == pSlow->val)
			return true;

		pSlow = pSlow->next;

	}
	return false;
}



int main()
{
	ListNode* head = new ListNode(0);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(4);
	head->next->next->next->next->next = head->next;
	cout << hasCycle(head);

	return 0;
}