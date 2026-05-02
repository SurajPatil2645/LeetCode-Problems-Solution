class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor_sum = 0;
        for (int n : nums) {
            xor_sum ^= n;
        }
        
        int mask = xor_sum & -xor_sum;
        int a = 0, b = 0;
        for (int n : nums) {
            if (n & mask) {
                a ^= n;
            } else {
                b ^= n;
            }
        }

        return {a, b};
    }
};
