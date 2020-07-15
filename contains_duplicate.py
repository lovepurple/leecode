"""
    217. Contains Duplicate 2018-8-8 0:05:01
    Given an array of integers, find if the array contains any duplicates.

    Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

    Example 1:

    Input: [1,2,3,1]
    Output: true
    Example 2:

    Input: [1,2,3,4]
    Output: false
    Example 3:

    Input: [1,1,1,3,3,4,3,2,4,2]
    Output: true
"""


class contains_duplicate:
    def containsDuplicate(self, nums):

        # 冒泡排序的时间复杂度太大
        """
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] == nums[j]:
                    return True

        return False
        """
        # 借助set数据结构，非常巧妙,set 本身就会去重复,但如果使用C 使用基础语言没有set的情况下，利用排序思想（快排）
        if len( set(nums)) == len(nums):
            return False

        return True


instance = contains_duplicate()
nums = [1, 1, 1, 3, 3, 4, 3, 2, 2, 4, 2]
print(instance.containsDuplicate(nums))
