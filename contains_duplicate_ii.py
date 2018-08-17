"""
    219. 2018-8-17 15:59:55
    Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and
    the absolute difference between i and j is at most k.

    Example 1:

    Input: nums = [1,2,3,1], k = 3
    Output: true

    Example 2:

    Input: nums = [1,0,1,1], k = 1
    Output: true
    Example 3:

    Input: nums = [1,2,3,1,2,3], k = 2
    Output: false
"""


class contains_duplicate_ii:
    def containsNearbyDuplicate(self, nums, k):

        keyIndexDict = {}
        for i in range(len(nums)):
            lastKeyIndex = keyIndexDict.get(nums[i])
            if lastKeyIndex != None:
                if i - lastKeyIndex <= k:
                    return True

            keyIndexDict[nums[i]] = i

        return False


instance = contains_duplicate_ii()
nums = [1, 2, 3, 1, 2, 3]
k = 2

print(instance.containsNearbyDuplicate(nums, k))
