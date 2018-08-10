"""
    9. 2018-8-10 19:42:17
    Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

    Example 1:

    Input: 121
    Output: true
    Example 2:

    Input: -121
    Output: false
    Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
    Example 3:

    Input: 10
    Output: false
    Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
"""


class palindrom_number:

    def isPalindrom(self, x):
        strNum = str(x)
        lenStrNum = len(strNum)

        for i in range((lenStrNum // 2) + 1):
            if strNum[i] != strNum[lenStrNum - i - 1]:
                return False

        return True

instance = palindrom_number()
num = -1

print(instance.isPalindrom(num))
