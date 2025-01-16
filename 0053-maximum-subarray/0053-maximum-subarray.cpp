class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum=0,maxsum=0;
        for(int val : nums){
            currSum+=val;
            maxsum=max(currSum,maxsum);

            if(currSum<0){
            currSum=0;
            }
        }
        return maxsum;
    }
};