#include <iostream>


using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* getKthFromEnd(ListNode* head, int k);
};

int main()
{
	Solution s;
	ListNode* phead = new ListNode(1);
	//ListNode* p1 = new ListNode(2);
	//phead->next = p1;

	ListNode* kthfromend = s.getKthFromEnd(phead, 1);

	cout << kthfromend;

	return 0;
}

ListNode* Solution::getKthFromEnd(ListNode* head, int k)
{
	//双指针
	ListNode* pSlow = head;
	ListNode* pFast = head;

	for (int i = 1; i < k; ++i)
	{
		if (pFast->next != nullptr)
			pFast = pFast->next;
		else
			return pFast;
	}

	while (pFast->next != nullptr)
	{
		pFast = pFast->next;
		pSlow = pSlow->next;
	}

	return pSlow;
}
