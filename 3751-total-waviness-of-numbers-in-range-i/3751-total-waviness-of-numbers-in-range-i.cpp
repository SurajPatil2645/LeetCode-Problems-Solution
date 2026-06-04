class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total_waviness = 0;
        
        for (int i = num1; i <= num2; ++i) {
            std::string s = std::to_string(i);
            int n = s.length();
            
            if (n < 3) continue;
            
            for (int j = 1; j < n - 1; ++j) {
                if (s[j] > s[j - 1] && s[j] > s[j + 1]) {
                    total_waviness++;
                } else if (s[j] < s[j - 1] && s[j] < s[j + 1]) {
                    total_waviness++;
                }
            }
        }
        
        return total_waviness;
    }
};