class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> nodes(n);
        for (int i = 0; i < n; ++i) {
            nodes[i] = {nums[i], i};
        }
        sort(nodes.begin(), nodes.end());

        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[nodes[i].second] = i;
        }

        int LOG = 18;
        vector<vector<int>> up(n, vector<int>(LOG));

        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j + 1 < n && nodes[j + 1].first - nodes[i].first <= maxDiff) {
                j++;
            }
            up[i][0] = j;
        }

        for (int k = 1; k < LOG; ++k) {
            for (int i = 0; i < n; ++i) {
                up[i][k] = up[up[i][k - 1]][k - 1];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int pu = pos[q[0]];
            int pv = pos[q[1]];
            
            if (pu == pv) {
                ans.push_back(0);
                continue;
            }
            
            if (pu > pv) swap(pu, pv);

            if (up[pu][LOG - 1] < pv) {
                ans.push_back(-1);
                continue;
            }

            int jumps = 0;
            int curr = pu;
            for (int k = LOG - 1; k >= 0; --k) {
                if (up[curr][k] < pv) {
                    curr = up[curr][k];
                    jumps += (1 << k);
                }
            }
            
            ans.push_back(jumps + 1);
        }

        return ans;
    }
};