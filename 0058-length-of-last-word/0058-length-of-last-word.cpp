class Solution {
public:
    int lengthOfLastWord(string s) {
        // int i = s.length() - 1;
        // while(i >= 0 && !isalpha(s[i])){
        //     i--;
        // }
        int count = 0;
        // while( i >= 0 && isalpha(s[i])){
        //     count++;
        //     i--;
        // }
        bool counting = false;
        for(int i = s.length()-1; i>=0;i--){
            if(s[i] != ' '){
                count++;
                counting = true;
            }
            else if(counting){
                break;
            }
        }
        return count;
    }
};