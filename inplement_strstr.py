"""
    28. Implement strStr()          2018-8-13 16:51:17
    Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

    Example 1:

    Input: haystack = "hello", needle = "ll"
    Output: 2
    Example 2:

    Input: haystack = "aaaaa", needle = "bba"
    Output: -1

    note: needle="" 的问题 0 (空是任何的子串)
"""


class implement_strstr:
    def strStr(self, hayStack, needle):

        indexOfSubStr = 0

        for i in range(len(needle)):
            indexOfChar = self.indexOfChar(haystack,needle[i])

            if indexOfChar == -1:
                return -1





    def indexOfChar(self, str, char,startIndex = 0):
        for i in range(startIndex,len(str)):
            ch = str[i]
            if ch == char:
                return i

        return -1


haystack = ""
needle=""
print(haystack.index(needle))