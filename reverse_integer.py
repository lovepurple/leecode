"""
    7. Reverse Integer
    2018-8-1 17:51:37

    Given a 32-bit signed integer, reverse digits of an integer.
    Example 1:

    Input: 123
    Output: 321

    Example 2:
    Input: -123
    Output: -321

    Example 3:
    Input: 120
    Output: 21

    note:需要判断是否超出32-bit
"""


class reverse_integer:
    intMin = ~(1 << 31)  # note: 32-bit int 的最大值与最小值取法
    intMax = 1 << 31

    def reverseInt(self, x):
        if self.isOverflow(x):
            return 0

        placeList = []
        sign = 1 if x > 0 else -1
        x *= sign

        place = x // 10
        placeNum = x % 10
        while placeNum > 0 or place > 0:
            placeList.append(placeNum)
            placeNum = place % 10
            place = place // 10

        reversedInt = 0
        for i in range(len(placeList)):
            reversedInt += placeList[i] * pow(10, (len(placeList) - i - 1))
        reversedInt *= sign

        if self.isOverflow(reversedInt):
            return 0
        else:
            return reversedInt


    def isOverflow(self, num):
        return True if num > self.intMax or num < self.intMin else False


instance = reverse_integer()
print(instance.reverseInt(1534236469))
