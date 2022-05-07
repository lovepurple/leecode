#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addLists2(ListNode* l1, ListNode* l2)
{
	stack<int> l1Stack;
	stack<int> l2Stack;

	while (l1 != nullptr || l2 != nullptr)
	{
		if (l1 != nullptr)
		{
			l1Stack.push(l1->val);
			l1 = l1->next;
		}

		if (l2 != nullptr)
		{
			l2Stack.push(l2->val);
			l2 = l2->next;
		}
	}


	ListNode* pSumHead = nullptr;
	while (!l1Stack.empty() || !l2Stack.empty())
	{
		int l1Value = 0;
		if (!l1Stack.empty())
		{
			l1Value = l1Stack.top();
			l1Stack.pop();
		}

		int l2Value = 0;
		if (!l2Stack.empty())
		{
			l2Value = l2Stack.top();
			l2Stack.pop();
		}

		int sumValue = l1Value + l2Value;
		if (sumValue > 9)
		{
			sumValue -= 10;
			if (l1Stack.empty())
				l1Stack.push(1);
			else
				l1Stack.top() += 1;
		}
		ListNode* pNode = new ListNode(sumValue);
		pNode->next = pSumHead;
		pSumHead = pNode;
	}

	return pSumHead;
}

int main()
{
	ListNode* l1 = new ListNode(6);
	/*l1->next = new ListNode(1);
	l1->next->next = new ListNode(7);*/

	ListNode* l2 = new ListNode(9);
	l2->next = new ListNode(9);
	l2->next->next = new ListNode(5);

	ListNode* pSum = addLists2(l1, l2);

	return 0;
}