class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> delta(2 * limit + 2, 0);
        int n = nums.size();

        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i];
            int b = nums[n - 1 - i];

            int low = min(a, b) + 1;
            int high = max(a, b) + limit;
            int sum = a + b;

            delta[low] -= 1;
            delta[high + 1] += 1;

            delta[sum] -= 1;
            delta[sum + 1] += 1;
        }

        int min_moves = n;
        int current_moves = n; 
        
        for (int i = 2; i <= 2 * limit; ++i) {
            current_moves += delta[i];
            min_moves = min(min_moves, current_moves);
        }

        return min_moves;
    }
};