class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0; // It was a 9, so it becomes 0 and carries over
        }
        
        // If we get here, all digits were 9s (e.g., 999 -> 000)
        // We need to add a 1 at the beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
