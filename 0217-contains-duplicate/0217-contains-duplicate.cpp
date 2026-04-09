class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(int val : nums){
            if(s.find(val) == s.end()){
                s.insert(val);
            }
            else{
                return true;
            }
        }
        return false;
    }
};