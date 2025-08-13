class Solution {
public:
    int reverse(int x) {
    long long rev = 0; // use long long to avoid overflow during calculation
        while (x != 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }
        // Check for 32-bit signed integer overflow
        if (rev < INT_MIN || rev > INT_MAX)
            return 0;
        return (int)rev;
    }
};