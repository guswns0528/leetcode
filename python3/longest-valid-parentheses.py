class Solution:

    def isValid(self, s, start, end):
        if (end - start) % 2 == 1:
            return False

        if start == end:
            return True

        if self.dp[start][end] is not None:
            return self.dp[start][end]

        if s[start] == '(' and s[end - 1] == ')':
            self.dp[start][end] = self.isValid(s, start + 1, end - 1)
        else:
            self.dp[start][end] = False

        if self.dp[start][end]:
            return True

        for i in range(start, end, 2):
            if self.isValid(s, start, i) and self.isValid(s, i, end):
                self.dp[start][end] = True
                break

        return self.dp[start][end]

    def longestValidParentheses(self, s: str) -> int:
        self.dp = [[None for i in range(len(s) + 1)] for j in range(len(s) + 1)]

        result = 0

        for i in range(len(s)):
            for j in range(i, len(s) + 1):
                if self.isValid(s, i, j):
                    result = max(result, j - i)

        return result

s = Solution()
print(s.longestValidParentheses('(()'))
print(s.longestValidParentheses(')()())'))

with open('tc') as f:
    print(s.longestValidParentheses(f.read()))
