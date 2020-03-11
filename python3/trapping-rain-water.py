from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) == 0:
            return 0
        lmax = [None for _ in height]
        rmax = [None for _ in height]

        prev_height = height[0]
        for i, v in enumerate(height):
            lmax[i] = prev_height
            prev_height = max(prev_height, v)

        prev_height = height[-1]
        for i in range(len(height) - 1, -1, -1):
            v = height[i]
            rmax[i] = prev_height
            prev_height = max(prev_height, v)

        result = 0
        for i, v in enumerate(height):
            wall_height = min(lmax[i], rmax[i])
            diff = wall_height - v
            result += max(diff, 0)

        return result

s = Solution()
print(s.trap([0,1,0,2,1,0,1,3,2,1,2,1]))
