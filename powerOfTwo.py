"""
    231.Power Of Two -2018-8-2 20:25:40
    Given an integer, write a function to determine if it is a power of two.

    Example 1:

    Input: 1
    Output: true
    Explanation: 20 = 1

    Example 2:

    Input: 16
    Output: true
    Explanation: 24 = 16
    Example 3:

    Input: 218
    Output: false
"""


class powerOfTwo:
    def isPowerOfTwo(self, n):

        if n <= 0:
            return False

        n = n / 2
        power = 0
        while n > 1:
            power += 1

            if self._frac(n) != 0:
                power = -1
                break
            else:
                n = n / 2

        return True if power != -1 else False

    def _frac(self, decimalNum):
        return decimalNum - int(decimalNum)


instance = powerOfTwo()
print(instance.isPowerOfTwo(-10))
