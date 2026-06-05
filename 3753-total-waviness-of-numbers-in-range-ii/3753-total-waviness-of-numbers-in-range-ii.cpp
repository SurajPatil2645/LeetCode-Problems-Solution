class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;
    Node dp[20][3][11][11];
    bool vis[20][3][11][11];

    Node dfs(int pos, bool tight, int state, int a, int b) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][state][a][b])
            return dp[pos][state][a][b];

        int limit = tight ? s[pos] - '0' : 9;
        Node res = {0, 0};

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (state == 0) {
                if (d == 0) {
                    Node child = dfs(pos + 1, ntight, 0, 10, 10);
                    res.cnt += child.cnt;
                    res.wav += child.wav;
                } else {
                    Node child = dfs(pos + 1, ntight, 1, 10, d);
                    res.cnt += child.cnt;
                    res.wav += child.wav;
                }
            }
            else if (state == 1) {
                Node child = dfs(pos + 1, ntight, 2, b, d);
                res.cnt += child.cnt;
                res.wav += child.wav;
            }
            else { 
                int add = ((b > a && b > d) || (b < a && b < d));

                Node child = dfs(pos + 1, ntight, 2, b, d);

                res.cnt += child.cnt;
                res.wav += child.wav + child.cnt * 1LL * add;
            }
        }

        if (!tight) {
            vis[pos][state][a][b] = true;
            dp[pos][state][a][b] = res;
        }

        return res;
    }

    long long solve(long long n) {
        if (n <= 0) return 0;

        s = to_string(n);
        memset(vis, 0, sizeof(vis));

        return dfs(0, true, 0, 10, 10).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};