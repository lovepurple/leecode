"""
    859. Buddy Strings

    Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.

    Example 1:
    Input: A = "ab", B = "ba"
    Output: true

    Example 2:
    Input: A = "ab", B = "ab"
    Output: false

    Example 3:
    Input: A = "aa", B = "aa"
    Output: true

    Example 4:
    Input: A = "aaaaaaabc", B = "aaaaaaacb"
    Output: true

    Example 5:
    Input: A = "", B = "aa"
    Output: false
    2018-8-2 23:34:28
"""


class buddyString:
    def buddyStrings(self, A, B):
        if len(A) != len(B):
            return False

        for i in range(len(A)):
            letterA = A[i]
            letterB = B[i]

            if letterA != letterB:
                if letterA == B[i + 1] and letterB == A[i + 1]:
                    return True
                else:
                    return False

        return True

instance = buddyString()
print(instance.buddyStrings("ab","ab"))

