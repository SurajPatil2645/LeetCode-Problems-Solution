class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        
        // Step 1: Precompute proper divisors for each length
        vector<vector<int>> divisors(n + 1);
        for (int len = 2; len <= n; ++len) {
            for (int d = 1; d < len; ++d) {
                if (len % d == 0) {
                    divisors[len].push_back(d);
                }
            }
        }
        
        // cost[i][j] = min changes to make s[i...j] a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                int min_changes = 1e9;
                
                for (int d : divisors[len]) {
                    int current_changes = 0;
                    for (int start = 0; start < d; ++start) {
                        int l = i + start;
                        int r = i + len - d + start;
                        while (l < r) {
                            if (s[l] != s[r]) {
                                current_changes++;
                            }
                            l += d;
                            r -= d;
                        }
                    }
                    min_changes = min(min_changes, current_changes);
                }
                cost[i][j] = min_changes;
            }
        }
        
        // Step 2: DP to partition suffix s[i...] into `parts` semi-palindromes
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
        dp[n][0] = 0;
        
        for (int parts = 1; parts <= k; ++parts) {
            int min_remaining_chars = 2 * (parts - 1);
            for (int i = 0; i <= n - 2 * parts; ++i) {
                for (int end = i + 1; end <= n - 1 - min_remaining_chars; ++end) {
                    dp[i][parts] = min(dp[i][parts], cost[i][end] + dp[end + 1][parts - 1]);
                }
            }
        }
        
        return dp[0][k];
    }
};