"""
    8.String to Integer
    2018-8-1 19:3:16
    Implement atoi which converts a string to an integer.

    The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

    The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

    If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

    If no valid conversion could be performed, a zero value is returned.

    Note:

    Only the space character ' ' is considered as whitespace character.
    Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
    Example 1:

    Input: "42"
    Output: 42
    Example 2:

    Input: "   -42"
    Output: -42
    Explanation: The first non-whitespace character is '-', which is the minus sign.
                 Then take as many numerical digits as possible, which gets 42.
    Example 3:

    Input: "4193 with words"
    Output: 4193
    Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
    Example 4:

    Input: "words and 987"
    Output: 0
    Explanation: The first non-whitespace character is 'w', which is not a numerical
                 digit or a +/- sign. Therefore no valid conversion could be performed.
    Example 5:

    Input: "-91283472332"
    Output: -2147483648
    Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
                 Thefore INT_MIN (−231) is returned.
"""


class atoi:
    def myAtoi(self, str):
        sign = 1
        placenumberlist = []
        hasinitialsign = False

        for ch in str:
            if len(placenumberlist) > 0:
                if self.isFigure(ch):
                    placenumberlist.append(ord(ch) - 48)
                else:
                    break
            else:
                if self.isWhiteSpace(ch):
                    if hasinitialsign:
                        return 0
                    else:
                        continue

                if self.isFigure(ch):
                    hasinitialsign = True
                    placenumberlist.append(ord(ch) - 48)
                else:
                    if not hasinitialsign:
                        if ch == '+':
                            hasinitialsign = True
                            sign = 1
                        elif ch == '-':
                            hasinitialsign = True
                            sign = -1
                        else:
                            break
                    else:
                        break

        num = 0
        for i in range(len(placenumberlist)):
            num += placenumberlist[i] * pow(10, len(placenumberlist) - i - 1)

        num *= sign
        num = self.checkOverFlow(num)
        return num

    def isWhiteSpace(self, char):
        return char == ' '

    def checkOverFlow(self, num):
        if num < ~(1 << 31) + 1:
            return ~(1 << 31) + 1
        elif num > (1 << 31) - 1:
            return (1 << 31) - 1
        else:
            return num

    def isFigure(self, ch):
        return ch >= '0' and ch <= '9'


instance = atoi()
str = "   -42"
print(instance.myAtoi(str))
str = "    +0 123"
print(instance.myAtoi(str))
str = "words and 987"
print(instance.myAtoi(str))
str = "+-2"
print(instance.myAtoi(str))
