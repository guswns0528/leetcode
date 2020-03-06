from typing import List
from itertools import permutations

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        i = len(nums) - 2
        while not (i < 0 or nums[i] < nums[i + 1]):
            i -= 1

        if i < 0:
            for i, v in enumerate(nums[::-1]):
                nums[i] = v
            return

        j = len(nums) - 1
        while not nums[j] > nums[i]:
            j -= 1

        nums[i], nums[j] = nums[j], nums[i]
        for j, v in enumerate(nums[i + 1:][::-1]):
            nums[i + 1 + j] = v

s = Solution()
v = [3, 2, 1]
s.nextPermutation(v)
print(v)
