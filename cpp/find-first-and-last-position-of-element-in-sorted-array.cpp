#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto range = equal_range(cbegin(nums), cend(nums), target);
        auto left = range.first;
        auto right = range.second;
        if (left == cend(nums) or *left != target)
            return {-1, -1};
        return {(int)distance(cbegin(nums), left), (int)distance(cbegin(nums), right) - 1};
    }
};

int main(void) {
    vector<int> input{5, 7, 7, 8, 8, 10};
    Solution s;

    auto result = s.searchRange(input, 8);
    cout << result[0] << ' ' << result[1] << '\n';

    result = s.searchRange(input, 6);
    cout << result[0] << ' ' << result[1] << '\n';

    return 0;
}
