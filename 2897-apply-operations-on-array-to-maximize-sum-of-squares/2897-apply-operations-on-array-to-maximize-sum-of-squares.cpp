class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bit_count(32, 0);
        for (int x : nums) {
            for (int i = 0; i < 31; ++i) {
                if ((x >> i) & 1) {
                    bit_count[i]++;
                }
            }
        }
        
        long long ans = 0;
        long long MOD = 1e9 + 7;
        
        for (int step = 0; step < k; ++step) {
            long long current_num = 0;
            for (int i = 0; i < 31; ++i) {
                if (bit_count[i] > 0) {
                    current_num |= (1LL << i);
                    bit_count[i]--;
                }
            }
            ans = (ans + (current_num * current_num) % MOD) % MOD;
        }
        
        return ans;
    }
};