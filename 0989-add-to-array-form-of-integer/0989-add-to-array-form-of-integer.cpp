class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i = num.size() - 1;
        vector<int> result;

        while (i >= 0 || k > 0) {
            if (i >= 0) {
                k += num[i--]; // Add the current digit to k
            }
            result.push_back(k % 10); // The last digit of k is our current position result
            k /= 10;                  // The rest of k acts as the 'carry'
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
