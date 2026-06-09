class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int max_val = *max_element(nums.begin(), nums.end());
        int min_val = *min_element(nums.begin(), nums.end());
        
        long long single_max_diff = max_val - min_val;
        
        return single_max_diff * k;
    }
};