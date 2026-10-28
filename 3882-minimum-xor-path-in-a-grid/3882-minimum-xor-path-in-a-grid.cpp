class Solution {
public:
    int minCost(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<unordered_set<int>>> dp(m, vector<unordered_set<int>>(n));
        
        dp[0][0].insert(grid[0][0]);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int xor_val : dp[i][j]) {
                    if (j + 1 < n) {
                        dp[i][j + 1].insert(xor_val ^ grid[i][j + 1]);
                    }
                    if (i + 1 < m) {
                        dp[i + 1][j].insert(xor_val ^ grid[i + 1][j]);
                    }
                }
            }
        }
        
        int min_xor = 2048;
        for (int xor_val : dp[m - 1][n - 1]) {
            min_xor = min(min_xor, xor_val);
        }
        
        return min_xor;
    }
};