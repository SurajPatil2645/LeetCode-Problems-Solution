class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i = 0, j = 0;
        
        // Merge two sorted arrays
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i++]);
            } else {
                merged.push_back(nums2[j++]);
            }
        }
        
        // Add remaining elements from nums1
        while (i < nums1.size()) {
            merged.push_back(nums1[i++]);
        }
        
        // Add remaining elements from nums2
        while (j < nums2.size()) {
            merged.push_back(nums2[j++]);
        }
        
        int totalSize = merged.size();
        
        // Find the median
        if (totalSize % 2 == 1) {
            return merged[totalSize / 2];  // Odd case
        } else {
            return (merged[totalSize / 2 - 1] + merged[totalSize / 2]) / 2.0;  // Even case
        }
    }
};
