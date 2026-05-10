class Solution {
public:
    int countHousePlacements(int n) {
        long long mod = 1e9 + 7;
        
        long long prev2 = 1;
        long long prev1 = 2;
        
        if (n == 1) return (prev1 * prev1) % mod;

        for (int i = 2; i <= n; i++) {
            long long current = (prev1 + prev2) % mod;
            prev2 = prev1;
            prev1 = current;
        }

        return (prev1 * prev1) % mod;
    }
};