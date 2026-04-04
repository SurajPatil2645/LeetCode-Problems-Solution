class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 0) return false;
        if(num == 0) return false;

        long int x = num;
        int y = 1;

        while(x - y > 0){
            x = (x + y) / 2;
            y = num / x;
        }
        if(x * x == num){
            return true;
        }
        return false;
    }
};