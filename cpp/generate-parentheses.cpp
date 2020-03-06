#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class Solution {
private:
    template <typename Results>
    void generate(Results& results, char* buf, int n, int pos, int used, int opened) {
        if (pos == n * 2) {
            if (used != n and opened != 0)
                return;
            buf[pos] = 0;
            results.emplace_back(buf);
            return;
        }

        if (used < n) {
            buf[pos] = '(';
            generate(results, buf, n, pos + 1, used + 1, opened + 1);
        }

        if (opened > 0) {
            buf[pos] = ')';
            generate(results, buf, n, pos + 1, used, opened - 1);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        unique_ptr<char[]> buf(new char[n * 2 + 1]);
        generate(result, buf.get(), n, 0, 0, 0);
        return result;
    }
};

int main(void) {
    Solution s;
    auto result = s.generateParenthesis(3);
    for (const auto& s: result) {
        cout << s << '\n';
    }

    return 0;
}
