"""
    Given a sorted (in ascending order) integer array nums of n elements and a target value,
    write a function to search target in nums.
    If target exists, then return its index, otherwise return -1.

    Input: nums = [-1,0,3,5,9,12], target = 9
    Output: 4
    Explanation: 9 exists in nums and its index is 4

    Input: nums = [-1,0,3,5,9,12], target = 2
    Output: -1
    Explanation: 2 does not exist in nums so return -1
"""


class BinarySearch:
    def search(self, nums, target):
        index = len(nums) // 2

        compareNum = nums[index]

        while compareNum != target:
            if compareNum > target:
                index = (index - 1) // 2
            else:
                index = index + (len(nums) - index) // 2

            compareNum = nums[index]

        return index



search = BinarySearch()
index = search.search([-1, 0, 3, 5, 9, 12], 3)
print(index)
