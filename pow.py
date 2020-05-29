"""
    50. Pow(x,n)  2018-8-6 19:46:25
    Implement pow(x, n), which calculates x raised to the power n (xn).

    Example 1:

    Input: 2.00000, 10
    Output: 1024.00000
    Example 2:

    Input: 2.10000, 3
    Output: 9.26100
    Example 3:

    Input: 2.00000, -2
    Output: 0.25000
    Explanation: 2-2 = 1/22 = 1/4 = 0.25
"""


class pow:
    def mypow(self, x, n):
        """
       :type x: float
       :type n: int
       :rtype: float
       """

        if -100.0 >= x or x >= 100.0:
            return 0.0

        if n <= -(1 << 31):
            return x

        if n >= (1 << 31) - 1:
            return x

        x = x if n > 0 else 1 / x
        n = n if n >= 0 else -n

        result = 1
        while n > 0:
            result *= x
            n -= 1

        return result


instance = pow()
print(instance.mypow(1, -2147483648))
