/*
	双指针获取循环链表的循环点
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
	ListNode* detectCycle(ListNode* head);

};

int main()
{
	ListNode* p0 = new ListNode(1);
	ListNode* p1 = new ListNode(2);
	ListNode* p2 = new ListNode(3);
	ListNode* p3 = new ListNode(4);
	ListNode* p4 = new ListNode(5);
	ListNode* p5 = new ListNode(6);
	ListNode* p6 = new ListNode(7);
	ListNode* p7 = new ListNode(8);

	p0->next = p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = p7;
	p7->next = p1;

	Solution solution;
	ListNode* pCycleStartNode = solution.detectCycle(p0);
	std::cout << pCycleStartNode->val << std::endl;

	system("pause");
	return 0;
}


ListNode* Solution::detectCycle(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return nullptr;

	//快慢指针，如果有环，快指针还能追上慢指针
	ListNode* pFast = head;			//都从head走才能保证 f  = 2 * s
	ListNode* pSlow = head;

	while (pFast != nullptr)
	{
		/*
			重合点， f = 2 * s
					f = s + n * b    (b 为环的长度)
				=>
					s = n * b		第一次重合时，s走了n * b

				 令 f = head
				 再次 走，
				 当再次相遇时， f = a
							  s = a + n * b
							  当前位置就是环的入口
		*/

		if (pFast->next == nullptr)
			return nullptr;

		pFast = pFast->next->next;
		pSlow = pSlow->next;

		if (pFast == pSlow)
			break;
	}

	if (pFast != nullptr)
	{
		pFast = head;
		//第二次 每次走一步 比较巧妙		相交点永远是 a + n*b 
		while (pFast != pSlow)
		{
			pFast = pFast->next;
			pSlow = pSlow->next;
		}

		return pFast;
	}

	return nullptr;
}
