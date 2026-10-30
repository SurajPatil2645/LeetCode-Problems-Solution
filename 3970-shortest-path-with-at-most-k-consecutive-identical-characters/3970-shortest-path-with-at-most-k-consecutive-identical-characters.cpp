class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }
        
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
        
        vector<vector<long long>> min_dist(n, vector<long long>(k + 1, -1));
        
        pq.push({0, 0, 1});
        min_dist[0][1] = 0;
        
        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();
            
            if (u == n - 1) {
                return d;
            }
            
            if (d > min_dist[u][count]) {
                continue;
            }
            
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                
                int next_count = (labels[u] == labels[v]) ? (count + 1) : 1;
                
                if (next_count <= k) {
                    if (min_dist[v][next_count] == -1 || d + w < min_dist[v][next_count]) {
                        min_dist[v][next_count] = d + w;
                        pq.push({d + w, v, next_count});
                    }
                }
            }
        }
        
        return -1;
    }
};