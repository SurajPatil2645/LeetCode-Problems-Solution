class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        set<int> s;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    // ans.push_back(nums[i]);
                    s.insert(nums1[i]);
                }
            }
        }
        for(int val : s){
            ans.push_back(val);
        }
        return ans;
    }
};