#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    template <typename Boards>
    bool checkRow(Boards& boards, int row) {
        bool exists[10] = { false, };

        for (auto column = 0; column < 9; column++) {
            auto v = boards[row][column] - '0';
            if (v < 0 or v > 9)
                continue;

            if (exists[v])
                return false;

            exists[v] = true;
        }

        return true;
    }

    template <typename Boards>
    bool checkColumn(Boards& boards, int column) {
        bool exists[10] = { false, };

        for (auto row = 0; row < 9; row++) {
            auto v = boards[row][column] - '0';
            if (v < 0 or v > 9)
                continue;

            if (exists[v])
                return false;

            exists[v] = true;
        }

        return true;
     }

    template <typename Boards>
    bool checkBox(Boards& boards, int row, int column) {
        bool exists[10] = { false, };

        for (auto inner_row = 0; inner_row < 3; inner_row++) {
            for (auto inner_column = 0; inner_column < 3; inner_column++) {
                auto row_ = row * 3 + inner_row;
                auto column_ = column * 3 + inner_column;
                auto v = boards[row_][column_] - '0';

                if (v < 0 or v > 9)
                    continue;

                if (exists[v])
                    return false;

                exists[v] = true;
            }
        }

        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (auto row = 0; row < 9; row++) {
            if (not checkRow(board, row))
                return false;
        }

        for (auto column = 0; column < 9; column++) {
            if (not checkColumn(board, column))
                return false;
        }

        for (auto row = 0; row < 3; row++) {
            for (auto column = 0; column < 3; column++) {
                if (not checkBox(board, row, column))
                    return false;
            }
        }

        return true;
    }
};

int main(void) {
    vector<vector<char>> board{
        {'.', '.', '.',  '.', '5', '.',  '.', '1', '.'},
        {'.', '4', '.',  '3', '.', '.',  '.', '.', '.'},
        {'.', '.', '.',  '.', '.', '3',  '.', '.', '1'},

        {'8', '.', '.',  '.', '.', '.',  '.', '2', '.'},
        {'.', '.', '2',  '.', '7', '.',  '.', '.', '.'},
        {'.', '1', '5',  '.', '.', '.',  '.', '.', '.'},

        {'.', '.', '.',  '.', '.', '2',  '.', '.', '.'},
        {'.', '2', '.',  '9', '.', '.',  '.', '.', '.'},
        {'.', '.', '4',  '.', '.', '.',  '.', '.', '.'}
    };

    Solution s;
    cout << s.isValidSudoku(board) << '\n';

    return 0;
}
