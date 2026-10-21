class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        
        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end());
        if (s == sorted_s) {
            return 0;
        }
        
        if (n == 2) {
            return -1;
        }
        
        char mn = sorted_s[0];
        char mx = sorted_s[n - 1];
        
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }
        
        bool only_mx_at_start = (s[0] == mx && count(s.begin(), s.end(), mx) == 1);
        bool only_mn_at_end = (s[n - 1] == mn && count(s.begin(), s.end(), mn) == 1);
        
        if (only_mx_at_start && only_mn_at_end) {
            return 3;
        }
        
        return 2;
    }
};