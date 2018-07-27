"""
    229.
        Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

        Note: The algorithm should run in linear time and in O(1) space.

        Example 1:
        Input: [3,2,3]
        Output: [3]

        Example 2:
        Input: [1,1,1,3,3,2,2,2]
        Output: [1,2]

        2018-7-27 11:41:29
"""


class majority_element:
    def majorityElement(self, nums):
        appearTimes = len(nums) // 3
        dict = {}
        result = []
        for i in range(len(nums)):
            keyAppearTime = dict.get(nums[i])
            if keyAppearTime is None:
                dict[nums[i]] = 0

            dict[nums[i]] += 1
            if dict[nums[i]] > appearTimes:
                if nums[i] not in result:
                    result.append(nums[i])

        return result


calculator = majority_element()
result = calculator.majorityElement([1, 1, 1, 3, 3, 2, 2, 2])
# result = calculator.majorityElement([3, 2, 3])
# result = calculator.majorityElement([2, 2])
print(result)
