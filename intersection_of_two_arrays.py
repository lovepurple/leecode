"""
    350. 2018-8-21 17:36:20
    Given two arrays, write a function to compute their intersection.

    Example 1:

    Input: nums1 = [1,2,2,1], nums2 = [2,2]
    Output: [2,2]
    Example 2:

    Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    Output: [4,9]
    Note:

    Each element in the result should appear as many times as it shows in both arrays.
    The result can be in any order.
    Follow up:

    What if the given array is already sorted? How would you optimize your algorithm?
    What if nums1's size is small compared to nums2's size? Which algorithm is better?
    What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

"""


class intersection_of_two_arrays:
    def intersect(self, nums1, nums2):
        # 先排序
        nums1 = self.__quickSort(nums1, 0, len(nums1) - 1)
        nums2 = self.__quickSort(nums2, 0, len(nums2) - 1)

        intersectionElements = []

        indexOfNum2 = 0
        for i in nums1:
            while indexOfNum2 < len(nums2):
                if nums2[indexOfNum2] == i:
                    intersectionElements.append(i)
                    indexOfNum2 += 1
                    break
                elif nums2[indexOfNum2] < i:
                    indexOfNum2 += 1
                else:
                    break

        return intersectionElements

    def __quickSort(self, nums, left, right):

        if right - left < 1:
            return nums

        i = left + 1
        j = right
        pivot = left

        while i <= j:
            while j >= left and nums[pivot] < nums[j]:
                j -= 1

            while i <= right and nums[pivot] > nums[i]:
                i += 1

            if i <= j:
                nums = self.__swap(nums, i, j)
                i += 1
                j -= 1

        nums = self.__swap(nums, pivot, j)

        nums = self.__quickSort(nums, left, j - 1)
        nums = self.__quickSort(nums, j + 1, right)

        return nums

    def __swap(self, num, i, j):
        if i == j:
            return num

        temp = num[i]
        num[i] = num[j]
        num[j] = temp
        return num


instance = intersection_of_two_arrays()

num1 = [1, 2, 2, 1]
num2 = [2, 2]
num1 = [4, 9, 5]
num2 = [9, 4, 9, 8, 4]
num1 = [3, 1, 2]
num2 = [1]
num1 = [1]
num2 = [1, 2]

print(instance.intersect(num1, num2))
