class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        int left = 0;
        for(int right=0;right<nums.size();right++){
            if(nums[right] != 0){
                swap(nums[right], nums[left++]);
            }
        }
        return nums;
    }
};