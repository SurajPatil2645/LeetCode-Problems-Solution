class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sq(n);
        for (int i = 0; i < n; ++i) {
            long long val = nums[i];
            sq[i] = val * val;
        }
        
        sort(sq.begin(), sq.end());
        
        long long score = 0;
        int mid = n / 2;
        
        for (int i = 0; i < mid; ++i) {
            score -= sq[i];
        }
        
        for (int i = mid; i < n; ++i) {
            score += sq[i];
        }
        
        return score;
    }
};