class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return '1'

        prev = self.countAndSay(n - 1)
        result = ''
        while len(prev) != 0:
            c = prev[0]
            count = 1
            i = 1
            while i < len(prev):
                if c != prev[i]:
                    break
                else:
                    count += 1
                i += 1
            prev = prev[i:]
            result += str(count) + c

        return result

s = Solution()
for i in range(10):
    print(s.countAndSay(i + 1))
