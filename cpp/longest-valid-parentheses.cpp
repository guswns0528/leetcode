#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(const string& s) {

        auto result = 0;
        stack<int> stack;
        stack.emplace(-1);

        for (auto i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack.emplace(i);
            }
            else {
                stack.pop();
                if (stack.empty()) {
                    stack.emplace(i);
                }
                else {
                    result = max(result, i - stack.top());
                }
            }
        }

        return result;
    }
};

int main(void) {

    Solution s;
    cout << s.longestValidParentheses("(()") << '\n';
    cout << s.longestValidParentheses(")()())") << '\n';

    ifstream ifs("tc");
    string str;
    ifs >> str;
    cout << s.longestValidParentheses(str) << '\n';

    return 0;
}
