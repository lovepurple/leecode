#include <iostream>


struct ListNode {
	int val;
	struct ListNode* next;
};

class Solution
{
public:
	ListNode* reverseKGroup(ListNode* head, int k);

};

int main()
{

	return 0;
}

ListNode* Solution::reverseKGroup(ListNode* head, int k)
{
	ListNode* pGroupHead = head;
	int groupCount = 0;

	while (head != nullptr)
	{
		groupCount++;
		head = head->next;

		if (groupCount == k)
		{
			for (int i = 0; i < k; ++i)
			{
				ListNode* pTemp;
				pGroupHead->next->next = pGroupHead;

			}
			
		}


	}

	return nullptr;
}
