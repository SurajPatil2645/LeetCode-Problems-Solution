class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> charCounts;
        for (char c : s) {
            charCounts[c]++;
        }

        int length = 0;
        bool hasOdd = false;

        for (auto& [ch, count] : charCounts) {
            if (count % 2 == 0) {
                length += count;
            } else {
                length += count - 1;
                hasOdd = true;
            }
        }

        if (hasOdd) {
            length += 1;
        }

        return length;
    }
};