"""
    21. 2018-8-10 22:26:01
    Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together
    the nodes of the first two lists.

    Example:

    Input: 1->2->4, 1->3->4
    Output: 1->1->2->3->4->4
"""


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class merge_two_sorted_list:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1:ListNode[int]
        :type l2:ListNode[int]
        :rtype:ListNode[int]
        """
        headPtr = l1
        dummy = headPtr

        while dummy.next is not None:
            while l2.next is not None:








def listTolinklist(list):
    """
    :type list:List[int[
    :return:
    """
    headPtr = ListNode(list[0])
    dummy = headPtr

    for i in list:
        dummy.next = ListNode(i)
        dummy = dummy.next

    return headPtr.next


l1 = [1, 2, 4]
l2 = [1, 3, 4]
listTolinklist(l2)
