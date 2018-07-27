"""
    Given an array of integers, return indices of the two numbers such that they add up to a specific target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    Given nums = [2, 7, 11, 15], target = 9,
    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].

    2018-7-26 19:34:10
"""


class twoSum:
    def findSumIndices(self, nums, target):
        result = []
        for i in range(len(nums)):
            oneNum = nums[i]
            for j in range(i + 1, len(nums)):
                twoNum = nums[j]
                if oneNum + twoNum == target:
                    result.append(i)
                    result.append(j)

        return result


calculator = twoSum()
result = calculator.findSumIndices([2, 7, 0,9, 15], 9)
print(result)
