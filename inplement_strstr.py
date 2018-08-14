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
    def strStr(self, haystack, needle):

        # 0 是任何串的子串
        if len(needle) == 0:
            return 0

        if len(haystack) < len(needle):
            return -1

        currentIndex = 0
        while currentIndex != -1 or currentIndex < len(haystack):
            currentIndex = self.indexOfChar(haystack, needle[0], currentIndex)

            if currentIndex != -1:
                for i in range(len(needle)):
                    chNeedle = needle[i]
                    if i + currentIndex >= len(haystack):
                        return -1

                    chInHayStack = haystack[i + currentIndex]

                    if chNeedle != chInHayStack:
                        currentIndex +=1
                        break
                    else:
                        if i == len(needle) - 1:
                            return currentIndex
            else:
                break

        return currentIndex

    def indexOfChar(self, str, char, startIndex=0):
        for i in range(startIndex, len(str)):
            ch = str[i]
            if ch == char:
                return i

        return -1


haystack = "mississippi"
needle = "issip"

instance = implement_strstr()
print(instance.strStr(haystack, needle))
