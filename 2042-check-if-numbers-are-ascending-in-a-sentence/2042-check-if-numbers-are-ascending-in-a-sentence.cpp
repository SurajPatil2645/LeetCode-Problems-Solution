class Solution {
public:
    
    bool areNumbersAscending(string s) {
        stringstream ss(s);
        string token;
        int prev = -1;

        while (ss >> token) {
            if (isdigit(token[0])) {
                int current = stoi(token);
                if (current <= prev) {
                    return false;
                }
                prev = current;
            }
        }
        return true;
    }
};