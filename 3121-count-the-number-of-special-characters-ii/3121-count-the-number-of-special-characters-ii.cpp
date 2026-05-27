class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> last_lower(26, -1);
        vector<int> first_upper(26, -1);
        
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            if (islower(c)) {
                last_lower[c - 'a'] = i;
            } else {
                int idx = c - 'A';
                if (first_upper[idx] == -1) {
                    first_upper[idx] = i;
                }
            }
        }
        
        int special_count = 0;
        
        for (int i = 0; i < 26; ++i) {
            if (last_lower[i] != -1 && first_upper[i] != -1) {
                if (last_lower[i] < first_upper[i]) {
                    special_count++;
                }
            }
        }
        
        return special_count;
    }
};