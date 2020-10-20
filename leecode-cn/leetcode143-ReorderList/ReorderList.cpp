#include <iostream>

using namespace std;

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
	/*
		1. 使用快慢指针找到中间节点
		2. 从中间节点开始反转后面的节点
		3. 合并两个链表
	*/
	void reorderList(ListNode* head);

private:
	ListNode* getListMidNode(ListNode* head);

	ListNode* reverseList(ListNode* head);
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

	s.reorderList(pNode0);
	
	cout << "sss";

	return 0;
}

void Solution::reorderList(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return;

	ListNode* pMidNode = getListMidNode(head);
	ListNode* pReversedHead = reverseList(pMidNode);

	while (head != nullptr && pReversedHead != nullptr)
	{
		ListNode* pHeadNext = head->next;
		ListNode* pReverseHeadNext = pReversedHead->next;
		head->next = pReversedHead;
		pReversedHead->next = pHeadNext;

		head = pHeadNext;
		pReversedHead = pReverseHeadNext;
	}
}

ListNode* Solution::reverseList(ListNode* head)
{
	if (head == nullptr)
		return nullptr;

	if (head->next == nullptr)
		return head;

	ListNode* pNode = reverseList(head->next);

	ListNode* pTemp = pNode;
	while (pTemp->next != nullptr)
		pTemp = pTemp->next;

	pTemp->next = head;
	head->next = nullptr;

	return pNode;
}


//快慢指针找中点
ListNode* Solution::getListMidNode(ListNode* head)
{
	ListNode* pFast = head;
	ListNode* pSlow = head;

	while (pFast->next != nullptr && pFast->next->next != nullptr)
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;
	}

	return pSlow;
}
