"""
    29. 2018-8-16 19:0:2
    Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

    Return the quotient after dividing dividend by divisor.

    The integer division should truncate toward zero.

    Example 1:

    Input: dividend = 10, divisor = 3
    Output: 3
    Example 2:

    Input: dividend = 7, divisor = -3
    Output: -2
    Note:

    Both dividend and divisor will be 32-bit signed integers.
    The divisor will never be 0.
    Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
     For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
"""


class divide_two_integers:
    def divide(self, dividend, divisor):
        if divisor < (-1) << 31 or divisor > ((1 << 31) - 1):
            return ((1 << 31) - 1)

        sign = 1
        if dividend < 0:
            sign *= -1
            dividend = -dividend

        if divisor < 0:
            sign *= -1
            divisor = -divisor

        result = 0

        while dividend >= divisor:
            dividend -= divisor
            result += 1

        if result < (-1) << 31 or result > ((1 << 31) - 1):
            return ((1 << 31) - 1)
        else:
            return result * sign


instance = divide_two_integers()
divided = 7
divisor = -3

print(instance.divide(divided, divisor))
