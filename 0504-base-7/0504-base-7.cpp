class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";

        bool isNegative = num < 0;
        long long n = abs((long long)num);
        string res = "";

        while (n > 0) {
            res += to_string(n % 7);
            n /= 7;
        }

        if (isNegative) res += '-';

        reverse(res.begin(), res.end());
        
        return res;
    }
};