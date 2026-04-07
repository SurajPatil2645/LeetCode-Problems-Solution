class Solution {
public:
    int hammingWeight(int n) {
        vector<int> s;
        while(n>0){
            s.push_back(n%2);
            n = n/2;
        }
        int count = 0;
        for(int val : s){
            if(val == 1){
                count++;
            }
        }
        return count;
    }
};