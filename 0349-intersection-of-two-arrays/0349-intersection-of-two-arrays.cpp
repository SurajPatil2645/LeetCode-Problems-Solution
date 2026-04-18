class Solution {
public:
    // vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //     vector<int> ans;
    //     set<int> s;
    //     for(int i=0;i<nums1.size();i++){
    //         for(int j=0;j<nums2.size();j++){
    //             if(nums1[i]==nums2[j]){
    //                 // ans.push_back(nums[i]);
    //                 s.insert(nums1[i]);
    //             }
    //         }
    //     }
    //     for(int val : s){
    //         ans.push_back(val);
    //     }
    //     return ans;
    // }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> ans;
        for (int x : nums2) {
            if (s.erase(x)) { // erase returns 1 if element existed, 0 otherwise
                ans.push_back(x);
            }
        }
        return ans;
    }
};