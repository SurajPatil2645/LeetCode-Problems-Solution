#include <string>
#include <algorithm>

class Solution {
public:
    std::string maxSumOfSquares(int num, int sum) {
        if (sum < 1 || sum > 9 * num) {
            return "";
        }
        
        std::string ans(num, '0');
        
        for (int i = 0; i < num; ++i) {
            // We want to place the largest possible digit (up to 9) at the current position.
            // But we must leave enough sum for the remaining (num - 1 - i) positions,
            // AND we want to maximize the sum of squares. 
            // Wait! To maximize the sum of squares, we should make the digits as LARGE as possible,
            // not spread them out. So we should greedily take 9 whenever we can afford it, 
            // as long as the remaining sum can still be formed by the remaining slots.
            
            int max_remaining_slots = num - 1 - i;
            // The maximum sum the remaining slots can hold is 9 * max_remaining_slots.
            // Therefore, the current digit cannot be less than: sum - 9 * max_remaining_slots.
            int min_current = std::max(0, sum - 9 * max_remaining_slots);
            
            // To make the integer value *itself* as large as possible when scores tie, 
            // we actually want larger digits on the left. Wait, taking the *maximum* possible digit 
            // for the current position gives us the largest integer value!
            // Let's take the maximum valid digit for this position:
            int current_digit = std::min(9, sum);
            
            // But wait, if we take 9, does it leave enough for the rest? 
            // We must ensure sum - current_digit <= 9 * max_remaining_slots, 
            // which means current_digit >= sum - 9 * max_remaining_slots.
            current_digit = std::max(current_digit, sum - 9 * max_remaining_slots);
            
            ans[i] = '0' + current_digit;
            sum -= current_digit;
        }
        
        return ans;
    }
};