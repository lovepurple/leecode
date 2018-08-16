"""
    278. 2018-8-16 18:15:47
    You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

    Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

    You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

    Example:

    Given n = 5, and version = 4 is the first bad version.

    call isBadVersion(3) -> false
    call isBadVersion(5) -> true
    call isBadVersion(4) -> true

    Then 4 is the first bad version.

    同样是二分法  这个例子带边界值
"""


def isBadVersion(version):
    return True if version >= 6 else False


class first_bad_version:

    def firstBadVersion(self, n):
        return self.findBadVersion(0, n)

    def findBadVersion(self, left, right):

        if right - left == 1:
            if not isBadVersion(left) and isBadVersion(right):
                return right
        else:
            middleVersion = (right + left) // 2

            if isBadVersion(middleVersion):
                return self.findBadVersion(left, middleVersion)
            else:
                return self.findBadVersion(middleVersion, right)


instance = first_bad_version()
print(instance.firstBadVersion(7))