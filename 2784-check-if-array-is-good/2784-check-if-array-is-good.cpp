class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = 0;
        for (int num : nums) {
            n = max(n, num);
        }

        if (nums.size() != n + 1) {
            return false;
        }

        vector<int> count(n + 1, 0);
        for (int num : nums) {
            count[num]++;
        }

        for (int i = 1; i < n; i++) {
            if (count[i] != 1) return false;
        }
        
        return count[n] == 2;
    }
};