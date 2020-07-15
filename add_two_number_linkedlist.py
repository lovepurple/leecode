"""
    2. Add Two Numbers
    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and
    each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Example:

    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.
"""


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class add_two_number:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1:ListNode
        :type l2:ListNode
        :rtype:ListNode
        """
        if l1 is None or l2 is None:
            return 0

        result = ListNode(l1.val + l2.val)

        dummy = result
        while l1.next is not None:
            if l2.next is None:
                return 0

            l1 = l1.next
            l2 = l2.next
            addResultNode = self.addSingleNum(l1, l2)

            dummy.next = addResultNode
            dummy = dummy.next

        return result

    def addSingleNum(self, l1, l2):

        addResultNode = ListNode(l1.val + l2.val)
        if addResultNode.val > 9:
            addResultNode.val -= 10

            if l1.next is None:
                l1.next = ListNode(1)
            else:
                l1.next.val += 1

        return addResultNode


def listtolinkedlist(inputList):
    if len(inputList) < 0:
        return None

    headPtr = ListNode(inputList[0])
    dummy = headPtr
    for i in inputList:
        dummy._next = ListNode(i)
        dummy = dummy._next

    headPtr = headPtr._next

    return headPtr


l1 = [5]
l2 = [5]

linkedl1 = listtolinkedlist(l1)
linkedl2 = listtolinkedlist(l2)

instance = add_two_number()
resultPtr = instance.addTwoNumbers(linkedl1, linkedl2)
print(resultPtr)
