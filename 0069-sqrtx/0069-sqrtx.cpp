class Solution {
public:
    int mySqrt(int n) {
    if (n < 0) return -1; // Handle negative input
    if (n == 0) return 0;

    long int x = n; // Initial guess
    int y = 1;

    while (x - y > 0) {
        x = (x + y) / 2;
        y = n / x;
    }
    return x;
    }
};