class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component_ids(n, 0);
        int current_component = 0;
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                current_component++;
            }
            component_ids[i] = current_component;
        }
        
        vector<bool> ans;
        ans.reserve(queries.size());
        
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            ans.push_back(component_ids[u] == component_ids[v]);
        }
        
        return ans;
    }
};