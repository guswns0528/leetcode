from typing import List

class Solution:

    def collect(self, candidates: List[int], target: int, last: int, combination: List[int], result: List[List[int]]) -> None:
        if target == 0:
            result.append(list(combination))
            return

        for i in range(last, len(candidates)):
            v = candidates[i]
            if target < v:
                return

            combination.append(v)
            self.collect(candidates, target - v, i, combination, result)
            combination.pop()

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        self.collect(sorted(candidates), target, 0, [], result)
        return result

s = Solution()
print(s.combinationSum([2, 3, 6, 7], 7))
