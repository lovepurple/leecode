"""
    232. 2018-8-22 16:15:21
    Implement the following operations of a queue using stacks.

    push(x) -- Push element x to the back of queue.
    pop() -- Removes the element from in front of queue.
    peek() -- Get the front element.
    empty() -- Return whether the queue is empty.
    Example:

    MyQueue queue = new MyQueue();

    queue.push(1);
    queue.push(2);
    queue.peek();  // returns 1
    queue.pop();   // returns 1
    queue.empty(); // returns false
    Notes:

    You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
    Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
    You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
"""


class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._data=[]

    def push(self, x):
        """
        Push element x to the back of queue.
        :type x: int
        :rtype: void
        """
        self._data.append(x)


    def pop(self):
        """
        Removes the element from in front of queue and returns that element.
        :rtype: int
        """
        if self.empty():
            return None
        else:
            val = self.peek()
            self._data.remove(val)
            return val


    def peek(self):
        """
        Get the front element.
        :rtype: int
        """
        if self.empty():
            return None
        else:
            return self._data[0]

    def empty(self):
        """
        Returns whether the queue is empty.
        :rtype: bool
        """
        return len(self._data) == 0