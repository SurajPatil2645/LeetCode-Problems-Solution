#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    static const int MOD = 1e9 + 7;

    vector<long long> tree_sum;
    vector<long long> tree_squares;
    vector<long long> lazy;
    int n;

    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            int mid = (l + r) / 2;
            apply(2 * node, l, mid, lazy[node]);
            apply(2 * node + 1, mid + 1, r, lazy[node]);
            lazy[node] = 0;
        }
    }

    void apply(int node, int l, int r, long long val) {
        long long len = (r - l + 1);
        // (c + val)^2 = c^2 + 2*c*val + val^2
        // Update sum of squares: S_new = S_old + 2 * val * sum + val^2 * len
        tree_squares[node] = (tree_squares[node] + 2 * val * tree_sum[node] % MOD + val * val % MOD * len) % MOD;
        // Update linear sum: sum_new = sum + val * len
        tree_sum[node] = (tree_sum[node] + val * len) % MOD;
        // Accumulate lazy tag
        lazy[node] = (lazy[node] + val) % MOD;
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr, val);
        update(2 * node + 1, mid + 1, r, ql, qr, val);
        tree_sum[node] = (tree_sum[node * 2] + tree_sum[node * 2 + 1]) % MOD;
        tree_squares[node] = (tree_squares[node * 2] + tree_squares[node * 2 + 1]) % MOD;
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree_squares[node];
        push(node, l, r);
        int mid = (l + r) / 2;
        return (query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr)) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree_sum.assign(4 * n, 0);
        tree_squares.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> last_seen;
        long long total_sum = 0;
        long long current_sum_squares = 0;

        for (int i = 0; i < n; ++i) {
            int l = last_seen.count(nums[i]) ? last_seen[nums[i]] + 1 : 0;
            int r = i;

            update(1, 0, n - 1, l, r, 1);

            last_seen[nums[i]] = i;

            long long current_total = query(1, 0, n - 1, 0, i);
            total_sum = (total_sum + current_total) % MOD;
        }

        return total_sum;
    }
};