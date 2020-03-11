from typing import Tuple

class Solution:
    def extend(self, num1: str, num2: str) -> Tuple[str, str]:
        max_length = max(len(num1), len(num2))
        num1 = num1.ljust(max_length, '0')
        num2 = num2.ljust(max_length, '0')
        return num1, num2

    def do_add(self, num1: str, num2: str) -> str:
        result = ''
        carry = 0

        num1, num2 = self.extend(num1, num2)

        for v1, v2 in zip(num1, num2):
            v = int(v1) + int(v2) + carry
            carry = v // 10
            result += str(v % 10)

        if carry != 0:
            result += str(carry)

        return result

    def do_multiply(self, num1: str, num2: str) -> str:
        num1 = num1[::-1]
        num2 = num2[::-1]

        result = ''

        for i, v1 in enumerate(num1):
            temp = ''
            carry = 0
            for v2 in num2:
                v = int(v1) * int(v2) + carry
                carry = v // 10
                temp += str(v % 10)

            if carry != 0:
                temp += str(carry)

            temp = '0' * i + temp
            result = self.do_add(result, temp)

        return result[::-1]

    def multiply(self, num1: str, num2: str) -> str:
        if num1 == '0' or num2 == '0':
            return '0'

        if num1 == '1':
            return num2

        if num2 == '1':
            return num1

        return self.do_multiply(num1, num2)

s = Solution()
print(s.multiply('9' * 110, '9' * 110))
