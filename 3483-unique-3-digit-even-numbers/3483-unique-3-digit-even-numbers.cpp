class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // Count the frequency of each digit in the input
        vector<int> count(10, 0);
        for (int d : digits) {
            count[d]++;
        }
        
        int validNumbers = 0;
        
        // Check every 3-digit even number
        for (int num = 100; num <= 998; num += 2) {
            vector<int> currentCount(10, 0);
            int temp = num;
            
            // Extract each digit and count requirements
            while (temp > 0) {
                currentCount[temp % 10]++;
                temp /= 10;
            }
            
            // Verify if we have enough of each digit to form 'num'
            bool canForm = true;
            for (int i = 0; i < 10; i++) {
                if (currentCount[i] > count[i]) {
                    canForm = false;
                    break;
                }
            }
            
            if (canForm) {
                validNumbers++;
            }
        }
        
        return validNumbers;
    }
};