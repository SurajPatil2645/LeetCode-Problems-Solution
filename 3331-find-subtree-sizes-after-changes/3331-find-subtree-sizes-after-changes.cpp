class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = static_cast<int>(parent.size());
        vector<vector<int>> initAdj(n);
        for (int i = 1; i < n; ++i) {
            initAdj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<int> closest(26, -1);

        auto findNewParents = [&](auto& self, int u) -> void {
            int ch = s[u] - 'a';
            int ancestor = closest[ch];
            if (ancestor != -1) {
                newParent[u] = ancestor;
            }

            int prev = closest[ch];
            closest[ch] = u;

            for (int v : initAdj[u]) {
                self(self, v);
            }

            closest[ch] = prev;
        };

        findNewParents(findNewParents, 0);

        vector<vector<int>> finalAdj(n);
        for (int i = 1; i < n; ++i) {
            finalAdj[newParent[i]].push_back(i);
        }

        vector<int> answer(n, 1);
        auto computeSubtreeSizes = [&](auto& self, int u) -> int {
            int sz = 1;
            for (int v : finalAdj[u]) {
                sz += self(self, v);
            }
            return answer[u] = sz;
        };

        computeSubtreeSizes(computeSubtreeSizes, 0);
        return answer;
    }
};