"""
    35. 2018-8-16 15:29:39
    Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

    You may assume no duplicates in the array.

    Example 1:

    Input: [1,3,5,6], 5
    Output: 2
    Example 2:

    Input: [1,3,5,6], 2
    Output: 1
    Example 3:

    Input: [1,3,5,6], 7
    Output: 4
    Example 4:

    Input: [1,3,5,6], 0
    Output: 0

    考虑使用分治做
    分治的极值 出口条件非常重要
"""


class search_insert_position:
    def searchInsert(self, nums, target):
        targetPos = self.findPosition(nums, target, 0, len(nums) - 1)
        return targetPos

    def findPosition(self, nums, target, left, right):
        # 二分
        if right - left <= 0:
            if nums[right] >= target:           #细想一下 位置问题 把第二超了 自己是第二
                return right
            elif nums[right] < target:
                return right + 1

        middle = left + (right + 1 - left) // 2
        if nums[middle] == target:
            return middle
        elif nums[middle] > target:
            return self.findPosition(nums, target, left, middle - 1)
        else:
            return self.findPosition(nums, target, middle + 1, right)


instance = search_insert_position()

nums = [1, 3, 5]
target = 4

print(instance.searchInsert(nums, target))
