#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto count = 0;
        for (auto i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};

int main(void) {
    vector<int> input1{3, 2, 2, 3};
    vector<int> input2{0, 1, 2, 2, 3, 0, 4, 2};

    Solution s;

    auto count = s.removeElement(input1, 3);
    for (auto i = 0; i < count; i++) {
        cout << input1[i] << ' ';
    }
    cout << '\n';

    count = s.removeElement(input2, 2);
    for (auto i = 0; i < count; i++) {
        cout << input1[i] << ' ';
    }
    cout << '\n';
    return 0;
}
