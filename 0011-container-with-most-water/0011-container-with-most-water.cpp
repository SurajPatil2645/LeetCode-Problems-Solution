class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_result = 0;
        int i = 0, j = height.size() - 1;

        while (i < j) {
            int area = (j - i) * min(height[i], height[j]); // Correct formula

            // Update max_result if new area is larger
            max_result = max(max_result, area);

            // Move the pointer with the smaller height
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return max_result;
    }
};
