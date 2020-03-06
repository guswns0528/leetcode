#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    template <typename Nums>
    int doSearch(const Nums& nums, int low, int high, int k) {
        if (high < low)
            return -1;

        auto mid = (low + high) / 2;
        if (k == nums[mid])
            return mid;

        if (k > nums[mid])
            return doSearch(nums, mid + 1, high, k);
        else
            return doSearch(nums, low, mid - 1, k);
    }

    template <typename Nums>
    int pivot(const Nums& nums, int low, int high) {
        if (high < low)
            return -1;
        if (high == low)
            return low;

        auto mid = (low + high) / 2;
        if (mid < high and nums[mid] > nums[mid + 1])
            return mid;

        if (low < mid and nums[mid] < nums[mid - 1])
            return mid - 1;

        if (nums[low] >= nums[mid])
            return pivot(nums, low, mid - 1);
        else
            return pivot(nums, mid + 1, high);
    }

public:
    int search(vector<int>& nums, int target) {
        auto p = pivot(nums, 0, nums.size() - 1);

        if (p == -1)
            return doSearch(nums, 0, nums.size() - 1, target);

        if (nums[p] == target)
            return p;

        if (nums[0] <= target)
            return doSearch(nums, 0, p - 1, target);
        else
            return doSearch(nums, p + 1, nums.size() - 1, target);
    }
};

int main(void) {
    vector<int> input{4, 5, 6, 7, 0, 1, 2};
    Solution s;

    cout << s.search(input, 0) << '\n';
    cout << s.search(input, 3) << '\n';

    return 0;
}
