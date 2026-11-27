class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = static_cast<int>(items.size());
        vector<int> freeCount(n, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    ++freeCount[i];
                }
            }
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; ++i) {
            int cost = items[i][1];
            int firstGain = 1 + freeCount[i];

            if (cost > budget) continue;

            // 1. First purchase of item i (at most once)
            for (int b = budget; b >= cost; --b) {
                dp[b] = max(dp[b], dp[b - cost] + firstGain);
            }

            // 2. Additional copies of item i (1 copy each, no extra freebies)
            for (int b = cost; b <= budget; ++b) {
                dp[b] = max(dp[b], dp[b - cost] + 1);
            }
        }

        return dp[budget];
    }
};