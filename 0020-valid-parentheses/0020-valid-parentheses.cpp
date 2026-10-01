class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) return false;

        stack<char> st;
        unordered_map<char, char> matching = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char c : s) {
            if (matching.count(c)) {
                if (st.empty() || st.top() != matching[c]) {
                    return false;
                }
                st.pop();
            } else {
                st.push(c);
            }
        }

        return st.empty();
    }
};