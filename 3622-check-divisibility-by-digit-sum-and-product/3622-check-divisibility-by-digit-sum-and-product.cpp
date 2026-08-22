class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int x = n;
        while(x>0){
            sum += x % 10;
            product *= x % 10;
            x /= 10;
        }
        int ans = sum + product;
        if(n % ans == 0){
            return true;
        }
        return false;
    }
};