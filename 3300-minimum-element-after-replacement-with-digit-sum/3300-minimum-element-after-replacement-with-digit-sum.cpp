class Solution {
public:
    int minElement(vector<int>& nums) {
        int min_val = INT_MAX;
        
        for (int num : nums) {
            int digit_sum = 0;
            int temp = num;
            
            while (temp > 0) {
                digit_sum += temp % 10;
                temp /= 10;
            }
            
            if (digit_sum < min_val) {
                min_val = digit_sum;
            }
        }
        
        return min_val;
    }
};