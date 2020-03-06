from typing import List, Dict
from itertools import permutations
from bisect import bisect_left
from collections import Counter

class Solution:

    def findSubstring(self, s: str, words: List[str]) -> List[int]:

        if len(words) == 0:
            return []

        word_freq = Counter(words)
        word_count = len(words)
        word_length = len(words[0])
        str_length = len(s)
        result = []

        for offset in range(word_length):
            chunks = [s[offset + i * word_length: offset + (i + 1) * word_length] for i in range((str_length - offset) // word_length)]
            freq = Counter()
            count = 0
            for j in range(len(chunks)):

                if count == word_count:
                    freq -= Counter([chunks[j - word_count]])
                    count -= 1

                count += 1
                freq += Counter([chunks[j]])

                if freq == word_freq:
                    result.append(offset + (j - word_count + 1) * word_length)

        return result

target = 'ab' * 10000
words = ['ab'] * 1000
s = Solution()
print(s.findSubstring(target, words))
