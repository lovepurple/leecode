"""
    quick sort :2018-8-8 20:15:2
    分治思想
    note:
        推导了好长时间。。。
        quick sort重要几点，
            1. pivot 选择
            2. i ,j 的移动 及交换
            3. 递归出口
            4. 每次递归都在最原始的array中折腾，只是使用不同的index
"""


class quick_sort:

    def quicksort(self, num, left, right):
        """
        :type num:List
        :type left: int
        :type right: int
        :rtype:List
        """
        # 递归退出条件,只有一个元素或right 比left小时
        if right - left < 1:  # note: 2018-8-21 20:19:12
            return num

        i = left + 1
        j = right
        pivot = left

        while i < j:  # 注意这里的条件 2018-8-21 20:18:57 note: 条件是 j<=i  所以while条件是 i<j
            # shift the right
            while j > left and num[j] > num[pivot]:
                j -= 1

            # shift the left
            while i <= right and num[i] < num[pivot]:
                i += 1

            # 交换，包括pivot的
            if i <= j:
                num = self.swap(num, i, j)
                i += 1
                j -= 1

        self.swap(num, j, pivot)  # 交换pivot 和j

        # sort the pivot left
        self.quicksort(num, left, j - 1)
        self.quicksort(num, j + 1, right)

        return num

    def swap(self, nums, i, j):
        temp = nums[j]
        nums[j] = nums[i]
        nums[i] = temp

        return nums


sortinstance = quick_sort()
nums = [5, 28, 19, 4, 5, 5, 46, 8, 45, 7, 29, 42, 50, 25, 7, 22, 27, 18, 14]
nums = [3, 1, 2]

print(sortinstance.quicksort(nums, 0, len(nums) - 1))
