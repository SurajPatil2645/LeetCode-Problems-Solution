// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans;
//         for(int i = 0;i<nums1.size();i++){
//             int cur = nums1[i];
//             int idx = 0;
//             bool found = false;
//             while(nums2[idx] != cur){
//                 idx++;
//             }
//             for(int j = idx;j<nums2.size();j++){
//                 if(cur<nums2[j]){
//                     ans.push_back(nums2[j]);
//                     found = true;
//                     break;
//                 }
//             }
//             if(!found){
//                 ans.push_back(-1);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater;
        stack<int> s;

        for (int num : nums2) {
            while (!s.empty() && s.top() < num) {
                next_greater[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        vector<int> ans;
        for (int num : nums1) {
            if (next_greater.count(num)) {
                ans.push_back(next_greater[num]);
            } else {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};
