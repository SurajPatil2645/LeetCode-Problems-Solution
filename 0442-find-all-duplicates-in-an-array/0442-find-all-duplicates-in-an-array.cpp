class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        set<int> s;
        for(int val : nums){
            if(s.count(val)){
                ans.push_back(val);
            } else{
                s.insert(val);
            }
        }
        return ans;
    }
};