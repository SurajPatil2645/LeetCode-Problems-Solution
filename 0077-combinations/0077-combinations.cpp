class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(1, n, k, current, result);
        return result;
    }

private:
    void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
        // Base case: combination is complete
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // Optimization: only loop if there are enough numbers left to reach size k
        for (int i = start; i <= n - (k - current.size()) + 1; ++i) {
            current.push_back(i);         // Choose the number
            backtrack(i + 1, n, k, current, result); // Recurse
            current.pop_back();          // Backtrack
        }
    }
};
