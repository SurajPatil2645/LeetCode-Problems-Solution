class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};  // Handle small input edge case

        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        answer.reserve(nums.size() / 3);  // Preallocate memory

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicate `i`

            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int localSum = nums[i] + nums[j] + nums[k];

                if (localSum < 0) { j++; continue; }
                if (localSum > 0) { k--; continue; }

                answer.push_back({nums[i], nums[j], nums[k]});

                // Skip duplicate `j` and `k`
                do { j++; } while (j < k && nums[j] == nums[j - 1]);
                do { k--; } while (j < k && nums[k] == nums[k + 1]);
            }
        }
        return answer;
    }
};
