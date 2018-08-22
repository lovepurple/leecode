"""
    225. 2018-8-22 15:58:38
    Implement the following operations of a stack using queues.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    empty() -- Return whether the stack is empty.
    Example:

    MyStack stack = new MyStack();

    stack.push(1);
    stack.push(2);
    stack.top();   // returns 2
    stack.pop();   // returns 2
    stack.empty(); // returns false
    Notes:

    You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
    Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
    You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
"""


class MyStack:
    def __init__(self):
        self._data = []

    def push(self, x):
        self._data.append(x)

    def pop(self):
        if self.empty():
            return None
        else:
            val = self.top()
            self._data.remove(val)
            return  val

    def empty(self):
        return len(self._data) == 0

    def top(self):
        return None if self.empty() else self._data[len(self._data) - 1]
