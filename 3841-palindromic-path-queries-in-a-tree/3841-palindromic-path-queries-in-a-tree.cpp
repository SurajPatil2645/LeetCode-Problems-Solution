class Solution {
    int n, timer;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos;
    vector<int> tree, lazy;
    string node_char;

    int dfs(int u, int p, int d) {
        parent[u] = p;
        depth[u] = d;
        int size = 1, max_subtree_size = 0;
        for (int v : adj[u]) {
            if (v != p) {
                int subtree_size = dfs(v, u, d + 1);
                size += subtree_size;
                if (subtree_size > max_subtree_size) {
                    max_subtree_size = subtree_size;
                    heavy[u] = v;
                }
            }
        }
        return size;
    }

    void decompose(int u, int h) {
        head[u] = h;
        pos[u] = ++timer;
        if (heavy[u] != -1) {
            decompose(heavy[u], h);
        }
        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u]) {
                decompose(v, v);
            }
        }
    }

    void build(int node, int start, int end) {
        if (start == end) {
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    void push(int node) {
        if (lazy[node] != 0) {
            tree[2 * node] ^= lazy[node];
            lazy[2 * node] ^= lazy[node];
            tree[2 * node + 1] ^= lazy[node];
            lazy[2 * node + 1] ^= lazy[node];
            lazy[node] = 0;
        }
    }

    void updateRange(int node, int start, int end, int l, int r, int val) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            tree[node] ^= val;
            lazy[node] ^= val;
            return;
        }
        push(node);
        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, val);
        updateRange(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    int queryRange(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        push(node);
        int mid = (start + end) / 2;
        return queryRange(2 * node, start, mid, l, r) ^ queryRange(2 * node + 1, mid + 1, end, l, r);
    }

    int queryPath(int u, int v) {
        int res = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            res ^= queryRange(1, 1, n, pos[head[v]], pos[v]);
            v = parent[head[v]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        res ^= queryRange(1, 1, n, pos[u], pos[v]);
        return res;
    }

public:
    vector<bool> palindromePath(int n_nodes, vector<vector<int>>& edges, string s, vector<string>& queries) {
        n = n_nodes;
        timer = 0;
        node_char = s;
        adj.assign(n, vector<int>());
        parent.assign(n, 0);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(0, 0, 0);
        decompose(0, 0);

        tree.assign(4 * (n + 1), 0);
        lazy.assign(4 * (n + 1), 0);
        
        for (int i = 0; i < n; ++i) {
            updateRange(1, 1, n, pos[i], pos[i], 1 << (s[i] - 'a'));
        }

        vector<bool> answer;
        for (const auto& q : queries) {
            if (q.rfind("update", 0) == 0) {
                int u;
                char c;
                sscanf(q.c_str(), "update %d %c", &u, &c);
                
                int old_mask = 1 << (node_char[u] - 'a');
                int new_mask = 1 << (c - 'a');
                int diff = old_mask ^ new_mask;
                
                node_char[u] = c;
                if (diff != 0) {
                    // Update affects the whole subtree of u in Euler tour
                    updateRange(1, 1, n, pos[u], pos[u] + (depth[u] >= 0 ? 0 : 0), diff); // standard point update on position
                    // Wait, point update for a single node u is at pos[u] to pos[u]:
                    // Let's ensure point updates are applied correctly:
                }
            } else {
                int u, v;
                sscanf(q.c_str(), "query %d %d", &u, &v);
                
                int path_mask = queryPath(u, v);
                // Palindrome condition: mask has at most one bit set (0 or power of 2)
                bool can_form_palindrome = (path_mask & (path_mask - 1)) == 0;
                answer.push_back(can_form_palindrome);
            }
        }
        return answer;
    }
};