"""
    719. 2018-7-31 18:6:5

    Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

    Example 1:
        Input:
        nums = [1,3,1]
        k = 1

        Output: 0
        Explanation:
        Here are all the pairs:
        (1,3) -> 2
        (1,1) -> 0
        (3,1) -> 2
        Then the 1st smallest distance pair is (1,1), and its distance is 0.
"""


class find_kth_smallest_pair_distance:

#    def smallestDistancePair(self, nums, k):


    def binaryInsert(self, sortedList, value):
