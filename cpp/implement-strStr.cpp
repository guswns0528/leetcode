#include <algorithm>
#include <string>

using namespace std;

class Solution {
    int strStr(const string& haystack, const string& needle) {
        if (needle.length() == 0)
            return 0;

        return haystack.find(needle);
    }
};
