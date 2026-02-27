class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwt=0;
        int lp=0, rp=height.size()-1;
        while(lp<rp){
            int w=rp-lp;
            int ht=min(height[lp],height[rp]);
            int curwt=w*ht;
            maxwt=max(maxwt,curwt);
            height[lp]<height[rp] ? lp++:rp--;
        }
        return maxwt;
    }
};