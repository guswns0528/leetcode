#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    const auto m = (int)matrix.size();
    const auto n = (int)matrix[0].size();
    const auto count = m * n;

    vector<int> result;
    result.reserve(count);

    for (auto step = 0; step * 2 < min(m, n); step++) {
      const auto cur_m = m - step * 2;
      const auto cur_n = n - step * 2;

      if (cur_m == 1 and cur_n == 1) {
        result.emplace_back(matrix[step][step]);
      }
      else if (cur_m == 1) {
        for (auto x = 0; x < cur_n; x++) {
          result.emplace_back(matrix[step][step + x]);
        }
      }
      else if (cur_n == 1) {
        for (auto y = 0; y < cur_m; y++) {
          result.emplace_back(matrix[step + y][step]);
        }
      }
      else {
        for (auto i = 0, y = 0, x = 0, dy = 0, dx = 1; i < 2 * (cur_m + cur_n) - 4; i++, y += dy, x += dx) {
          result.emplace_back(matrix[y + step][x + step]);
          if (y == 0 and x == cur_n - 1) {
            dy = 1;
            dx = 0;
          } else if (y == cur_m - 1 and x == cur_n - 1) {
            dy = 0;
            dx = -1;
          } else if (y == cur_m - 1 and x == 0) {
            dy = -1;
            dx = 0;
          }
        }
      }
    }

    return result;
  }
};

int main(void) {
  vector<vector<int>> matrix{
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };
  auto result = Solution().spiralOrder(matrix);
  for (auto v : result) {
    cout << v << ' ';
  }
  cout << '\n';
  return 0;
}
