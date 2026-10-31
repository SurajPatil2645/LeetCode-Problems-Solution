class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int MOD = 1e9 + 7;

        vector<vector<array<pair<int, int>, 2>>> go(m, vector<array<pair<int, int>, 2>>(n));

        auto getNext = [&](int r, int c, int dir) {
            int dr[] = {0, 1};
            int dc[] = {1, 0};
            
            int curr_r = r + dr[dir];
            int curr_c = c + dc[dir];
            int curr_dir = dir;

            while (curr_r >= 0 && curr_r < m && curr_c >= 0 && curr_c < n && grid[curr_r][curr_c] == 1) {
                curr_dir = 1 - curr_dir;
                curr_r += dr[curr_dir];
                curr_c += dc[curr_dir];
            }

            if (curr_r < 0 || curr_r >= m || curr_c < 0 || curr_c >= n) {
                return make_pair(-1, -1);
            }
            return make_pair(curr_r, curr_c);
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                go[i][j][0] = getNext(i, j, 0); 
                go[i][j][1] = getNext(i, j, 1); 
            }
        }

        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == 0) continue;

                auto [nr, nc] = go[i][j][0];
                if (nr != -1 && nc != -1) {
                    dp[nr][nc] = (dp[nr][nc] + dp[i][j]) % MOD;
                }

                auto [dr_idx, dc_idx] = go[i][j][1];
                if (dr_idx != -1 && dc_idx != -1) {
                    dp[dr_idx][dc_idx] = (dp[dr_idx][dc_idx] + dp[i][j]) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};