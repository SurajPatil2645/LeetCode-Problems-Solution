// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         vector<int> ans;
//         set<int> s;
//         for(int val : nums){
//             if(s.count(val)){
//                 ans.push_back(val);
//             } else{
//                 s.insert(val);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1; // Use value as index
            
            // If the value at this index is negative, we've seen it before
            if (nums[index] < 0) {
                ans.push_back(abs(nums[i]));
            } else {
                // Mark as visited by making it negative
                nums[index] = -nums[index];
            }
        }
        return ans;
    }
};