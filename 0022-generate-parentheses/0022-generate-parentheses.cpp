class Solution {
public:
    void backtrack(int n, int openCount, int closeCount, string current, vector<string>& result) {
        
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        if (openCount < n) {
            backtrack(n, openCount + 1, closeCount, current + "(", result);
        }

        if (closeCount < openCount) {
            backtrack(n, openCount, closeCount + 1, current + ")", result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(n, 0, 0, "", result);
        return result;
    }
};