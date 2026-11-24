class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            __int128 prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; ++j) {
                long long val = nums[j];
                prod *= val;
                g = (g == 0) ? val : std::gcd(g, val);
                l = l / std::gcd(l, val) * val;

                if (prod > 25200LL) {
                    break;
                }

                if (prod == static_cast<__int128>(l) * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};