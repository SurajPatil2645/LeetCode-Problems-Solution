class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp=0, bestbuy=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>bestbuy){
                maxp=max(maxp,prices[i]-bestbuy);
            }
            bestbuy=min(bestbuy,prices[i]);
        }
        return maxp;
    }
};