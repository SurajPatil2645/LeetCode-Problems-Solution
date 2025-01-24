class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;

        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int localSum = nums[i] + nums[j] + nums[k];
                if (localSum < 0) {
                    j++;
                } else if (localSum > 0) {
                    k--;
                } else {
                    answer.push_back({nums[i], nums[j], nums[k]});
                    // Skip duplicate values for the second element
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    // Skip duplicate values for the third element
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    j++;
                    k--;
                }
            }
        }
        return answer;
    }
};