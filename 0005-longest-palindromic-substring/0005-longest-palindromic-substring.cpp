class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 1;

        for (int i = 0; i < s.length(); i++) {
            // Odd length palindrome (center at i)
            expandAroundCenter(s, i, i, start, maxLen);
            // Even length palindrome (center between i and i+1)
            expandAroundCenter(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

private:
    void expandAroundCenter(const string &s, int left, int right, int &start, int &maxLen) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }

        int len = right - left - 1;
        if (len > maxLen) {
            start = left + 1;
            maxLen = len;
        }
    }
};