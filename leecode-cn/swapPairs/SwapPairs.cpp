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
	ListNode* swapPairs(ListNode* head);
};


int main()
{
	ListNode* pHead = new ListNode(1);
	ListNode* p1 = new ListNode(2);
	ListNode* p2 = new ListNode(3);
	ListNode* p3 = new ListNode(4);

	pHead->next = p1;
	p1->next = p2;
	p2->next = p3;


	Solution solution;
	solution.swapPairs(pHead);


	system("pause");
	return 0;
}

ListNode* nehead = nullptr;
ListNode* Solution::swapPairs(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return nullptr;


	ListNode* pTemp = head->next;
	head->next = pTemp->next;
	pTemp->next = head;

	if (nehead == nullptr) 
		nehead = pTemp;


	return swapPairs(head->next);
}
