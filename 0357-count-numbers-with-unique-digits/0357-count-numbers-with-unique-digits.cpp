class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        
        int total = 10;
        int uniqueChoicesForCurrentDigit = 9;
        int availableDigits = 9;
        
        
        for (int i = 2; i <= n && availableDigits > 0; i++) {
            uniqueChoicesForCurrentDigit *= availableDigits;
            total += uniqueChoicesForCurrentDigit;
            availableDigits--;
        }
        
        return total;
    }
};
