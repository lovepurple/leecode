/*
	递归反转链表
		swap(i,i+1)
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
	ListNode* reverseLinkedList(ListNode* pLinkedListRootNode);

	ListNode* reverseList(ListNode* head);

	void swapNode(ListNode* pListNode1, ListNode* pListNode2);

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

	ListNode* pTemp = pNode0;
	while (pTemp != nullptr)
	{
		std::cout << pTemp->val << "->";
		pTemp = pTemp->next;
	}

	std::cout << std::endl;

	Solution s;
	//ListNode* pReverseNode = s.reverseLinkedList(pNode0);

	//while (pReverseNode != nullptr)
	//{
	//	std::cout << pReverseNode->val << "->";
	//	ListNode* pNode = pReverseNode;
	//	pReverseNode = pReverseNode->next;
	//	//delete pNode;
	//}
	std::cout << "====================================================";
	s.reverseList(pNode0);

	system("pause");
	return 0;
}

ListNode* Solution::reverseLinkedList(ListNode* pLinkedListRootNode)
{
	if (pLinkedListRootNode == nullptr)
		return nullptr;

	ListNode* pNode2 = reverseLinkedList(pLinkedListRootNode->next);
	if (pNode2 == nullptr)
		return pLinkedListRootNode;

	swapNode(pLinkedListRootNode, pNode2);

	return pNode2;
}
/*
	递归： 管好当下，剩下交给递归
	1—>
		2- >
			3->
				4->
					5
	本质是1和剩下的交换

	另一个思路：改指针方向。。。
	1 -> 2 -> 3 ->4 -> 5
	1 <- 2 <- 3 <- 4 <- 5
*/
ListNode* Solution::reverseList(ListNode* head)
{
	if (head == nullptr)
		return NULL;

	if (head->next == nullptr)
		return head;

	ListNode* pReverseList = reverseList(head->next);
	swapNode(head, pReverseList);

	return pReverseList;		//返回的是交换后的头节点
}

void Solution::swapNode(ListNode* pListNode1, ListNode* pListNode2)
{
	if (pListNode1 == nullptr || pListNode2 == nullptr)
		return;

	ListNode* pTempNode2 = pListNode2;			//这里要找到子串的最后一个节点做交换
	while (pTempNode2->next != nullptr)
		pTempNode2 = pTempNode2->next;

	pListNode1->next = pTempNode2->next;
	pTempNode2->next = pListNode1;
}
