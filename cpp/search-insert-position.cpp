#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return distance(begin(nums), lower_bound(begin(nums), end(nums), target));
    }
};
