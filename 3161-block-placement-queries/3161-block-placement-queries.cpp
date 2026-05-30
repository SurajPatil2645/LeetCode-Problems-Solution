class Solution {
    vector<int> tree;
    int n;

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int queryMax(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        return max(queryMax(2 * node, start, mid, l, r),
                   queryMax(2 * node + 1, mid + 1, end, l, r));
    }

    void update_tree(int idx, int val) {
        update(1, 0, n, idx, val);
    }

    int query_tree(int l, int r) {
        if (l > r) return 0;
        return queryMax(1, 0, n, l, r);
    }

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_x = 0;
        for (const auto& q : queries) {
            max_x = max(max_x, q[1]);
        }
        
        n = max_x + 1;
        tree.assign(4 * n, 0);

        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(n); 
        
        update_tree(n, n);

        vector<bool> results;

        for (const auto& q : queries) {
            int type = q[0];
            if (type == 1) {
                int x = q[1];
                
                auto it = obstacles.upper_bound(x);
                int next_obs = *it;
                int prev_obs = *prev(it);
                
                obstacles.insert(x);
                
                update_tree(x, x - prev_obs);
                update_tree(next_obs, next_obs - x);
                
            } else {
                int x = q[1];
                int sz = q[2];
                
                auto it = obstacles.upper_bound(x);
                int prev_obs = *prev(it);
                
                int max_gap_before = query_tree(0, prev_obs);
                
                int last_stretch = x - prev_obs;
                
                if (max_gap_before >= sz || last_stretch >= sz) {
                    results.push_back(true);
                } else {
                    results.push_back(false);
                }
            }
        }

        return results;
    }
};