#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it = unique(begin(nums), end(nums));
        return distance(begin(nums), it);
    }
};

int main(void) {
    vector<int> input1{1, 1, 2};
    vector<int> input2{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    Solution s;

    cout << s.removeDuplicates(input1) << '\n';
    cout << s.removeDuplicates(input2) << '\n';

    return 0;
}
