from typing import List

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i, v in enumerate(nums):
            if v <= 0:
                nums[i] = n + 1

        for i, v in enumerate(nums):
            v = abs(v)
            if 1 <= v and v <= n:
                nums[v - 1] = -abs(nums[v - 1])

        for i, v in enumerate(nums):
            if v > 0:
                return i + 1
        return n + 1

s = Solution()
print(s.firstMissingPositive([7, 8, 9, 11, 12]))
