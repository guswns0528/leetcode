from typing import List, Set

class Solution:

    def collect(self, candidates: List[int], target: int, last: int, combination: List[int], result: Set[List[int]]) -> None:
        if target == 0:
            result.add(tuple(combination))
            return

        start = last + 1 if last != -1 else 0
        for i in range(start, len(candidates)):
            v = candidates[i]
            if target < v:
                return

            combination.append(v)
            self.collect(candidates, target - v, i, combination, result)
            combination.pop()

    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        result = set()
        self.collect(sorted(candidates), target, -1, [], result)
        return [list(x) for x in result]

s = Solution()
print(s.combinationSum([10,1,2,7,6,1,5], 8))
