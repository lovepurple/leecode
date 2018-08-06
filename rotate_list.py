"""
    61. Rotate List  2018-8-6 15:56:40
    Given a linked list, rotate the list to the right by k places, where k is non-negative.

    Example 1:
    Input: 1->2->3->4->5->NULL, k = 2
    Output: 4->5->1->2->3->NULL
    Explanation:
    rotate 1 steps to the right: 5->1->2->3->4->NULL
    rotate 2 steps to the right: 4->5->1->2->3->NULL

    Example 2:
    Input: 0->1->2->NULL, k = 4
    Output: 2->0->1->NULL
    Explanation:
    rotate 1 steps to the right: 2->0->1->NULL
    rotate 2 steps to the right: 1->2->0->NULL
    rotate 3 steps to the right: 0->1->2->NULL
    rotate 4 steps to the right: 2->0->1->NULL

    Note:leetcode 里对于输入的数据类型所有都是String，但用在函数里的会自动初始化对应的结构，
    例：
        # Definition for singly-linked list.
        # class ListNode:
        #     def __init__(self, x):
        #         self.val = x
        #         self.next = None

        class Solution:
            def rotateRight(self, head, k):

                :type head: ListNode
                :type k: int
                :rtype: ListNode


        def stringToIntegerList(input):
            return json.loads(input)

        def stringToListNode(input):
            # Generate list from the input
            numbers = stringToIntegerList(input)

            # Now convert that list into linked list
            dummyRoot = ListNode(0)
            ptr = dummyRoot
            for number in numbers:
                ptr.next = ListNode(number)
                ptr = ptr.next

            ptr = dummyRoot.next
            return ptr

        def listNodeToString(node):
            if not node:
                return "[]"

            result = ""
            while node:
                result += str(node.val) + ", "
                node = node.next
            return "[" + result[:-2] + "]"

        def main():
            import sys
            def readlines():
                for line in sys.stdin:
                    yield line.strip('\n')

            lines = readlines()
            while True:
                try:
                    line = next(lines)
                    head = stringToListNode(line);
                    line = next(lines)
                    k = int(line);

                    ret = Solution().rotateRight(head, k)

                    out = listNodeToString(ret);
                    print(out)
                except StopIteration:
                    break

        if __name__ == '__main__':
            main()

    对于本题，不需要自己处理把输入变成listNode，在RotateRight输入的head默认就是listNode
        
"""


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class rotate_list:
    def rotateRight(self, head, k):
        """
        :type head:ListNode
        :type k:int
        :rtype:ListNode
        """
        if head is None or head.next is None or k <= 0:
            return head

        dummy = head

        listNodeCount = 1
        while dummy.next != None:
            dummy = dummy.next
            listNodeCount += 1

        realK = k % listNodeCount
        while realK > 0:
            head = self.movetrailtohead(head, listNodeCount)
            realK -= 1

        return head

    def movetrailtohead(self, head, count):

        moveelement = None
        dummy = head

        for i in range(count - 2):
            dummy = dummy.next

        moveelement = dummy.next
        dummy.next = None
        moveelement.next = head

        head = moveelement

        return head


inputList = [1, 2, 3, 4, 5]

if len(inputList) > 0:
    headPtr = ListNode(inputList[0])

    tempNode = headPtr
    for num in inputList:
        tempNode.next = ListNode(num)
        tempNode.next = ListNode(num)
        tempNode = tempNode.next

    headPtr = headPtr.next

    instance = rotate_list()
    listafterrotate = instance.rotateRight(headPtr, 2)

