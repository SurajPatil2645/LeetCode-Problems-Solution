class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }

        string result = "";
        int n = s.length();
        int i = 0;

        while (i < n) {
            if (s[i] == '(') {
                i++;
                string key = "";
                while (i < n && s[i] != ')') {
                    key += s[i];
                    i++;
                }
                i++;

                if (dict.count(key)) {
                    result += dict[key];
                } else {
                    result += '?';
                }
            } else {
                result += s[i];
                i++;
            }
        }

        return result;
    }
};