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
	ListNode* swapPairs(ListNode* head);
};

int main()
{
	ListNode* pHead = new ListNode(1);
	pHead->next = new ListNode(2);
	pHead->next->next = new ListNode(3);
	pHead->next->next->next = new ListNode(4);

	Solution s;
	ListNode* pNodeAfterSwap = s.swapPairs(pHead);

	cout << pNodeAfterSwap;

	return 0;
}

ListNode* Solution::swapPairs(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;

	ListNode* pNode1 = head;
	ListNode* pNode2 = head->next;

	pNode1->next = swapPairs(pNode2->next);			//从底向上
	ListNode* pTempNode = pNode1;
	pNode2->next = pNode1;

	return pNode2;
}

