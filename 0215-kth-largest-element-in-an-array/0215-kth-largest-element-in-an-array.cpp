// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int, vector<int>, greater<int>> minHeap;
        
//         for (int num : nums) {
//             minHeap.push(num);
//             if (minHeap.size() > k) {
//                 minHeap.pop();
//             }
//         }
        
//         return minHeap.top();
//     }
// };

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }
};
