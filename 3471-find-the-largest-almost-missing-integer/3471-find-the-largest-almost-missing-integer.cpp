class Solution {
public:
    int largestInteger(std::vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        
        for (int num : nums) {
            freq[num]++;
        }

        int ans = -1;

        if (k == 1) {
            for (auto& [num, count] : freq) {
                if (count == 1) {
                    ans = max(ans, num);
                }
            }
        } else if (k == n) {
            for (int num : nums) {
                ans = max(ans, num);
            }
        } else {
            if (freq[nums[0]] == 1) {
                ans = std::max(ans, nums[0]);
            }
            if (freq[nums[n - 1]] == 1) {
                ans = std::max(ans, nums[n - 1]);
            }
        }

        return ans;
    }
};