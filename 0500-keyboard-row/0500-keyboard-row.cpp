class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> rowMap(26);
        string rows[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        
        for (int i = 0; i < 3; i++) {
            for (char c : rows[i]) {
                rowMap[c - 'a'] = i;
            }
        }
        
        vector<string> result;
        for (const string& word : words) {
            int targetRow = rowMap[tolower(word[0]) - 'a'];
            bool isValid = true;
            
            for (char c : word) {
                if (rowMap[tolower(c) - 'a'] != targetRow) {
                    isValid = false;
                    break;
                }
            }
            
            if (isValid) result.push_back(word);
        }
        
        return result;
    }
};
