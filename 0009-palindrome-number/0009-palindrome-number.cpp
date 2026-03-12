class Solution {
public:
    int reverse(int n){
        int revnum=0;
        while(n !=0){
            int dig=n%10;
            if(revnum > INT_MAX/10 || revnum < INT_MIN/10){
                return 0;
            }
            revnum=revnum*10+dig;
            n=n/10;
        }
        return revnum;
    }
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        // string s = to_string(x);
        // int n = s.length();
        
        // for (int i = 0; i < n / 2; i++) {
        //     if (s[i] != s[n - 1 - i]) {
        //         return false;
        //     }
        // }
        // return true;

        int revnum=reverse(x);
        return x==revnum;
    }
};