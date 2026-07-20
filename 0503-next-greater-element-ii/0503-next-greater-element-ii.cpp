class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st; // Stores indices

        // Traverse the array twice to handle circularity
        for (int i = 0; i < 2 * n; ++i) {
            int num = nums[i % n];
            
            // Pop elements from stack that are smaller than the current element
            while (!st.empty() && nums[st.top()] < num) {
                result[st.top()] = num;
                st.pop();
            }
            
            // Push index only during the first pass
            if (i < n) {
                st.push(i);
            }
        }

        return result;
    }
};