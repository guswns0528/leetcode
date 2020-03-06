from typing import List, Dict, Tuple
from itertools import product

class Solution:
    def parse(self, board: List[List[str]]) -> Dict[Tuple[int, int], str]:
        pass

    def solveSudoku(self, board: List[List[str]]) -> None:
        parsed = {tuple(k): set(range(1, 10)) for k in product(range(9))}

        for row in range(9):
            for column in range(9):
                if board[row][column] == '.':
                    continue

                v = int(board[row][column])
                parsed[(row, column)] = set([v])

                for r in range(9):
                    if r == row:
                        continue
                    parsed[(r, column)] -= set([v])

                for c in range(9):
                    if c == column:
                        continue
                    parsed[(row, c)] -= set([v])
