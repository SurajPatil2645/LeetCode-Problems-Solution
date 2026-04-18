class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int actual_sum = 0;
        for(int val : nums){
            actual_sum += val;
        }
        int expected_sum = (n * (n+1)) / 2;
        return expected_sum - actual_sum;
    }
};