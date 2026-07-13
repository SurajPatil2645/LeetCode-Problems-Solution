class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        
        for (int i = 1; i <= 9; ++i) {
            int num = i;
            int next_digit = i + 1;
            
            while (num <= high && next_digit <= 9) {
                num = num * 10 + next_digit;
                
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
                next_digit++;
            }
        }
        
        sort(result.begin(), result.end());
        
        return result;
    }
};