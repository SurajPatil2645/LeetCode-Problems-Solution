class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count=1;
        int l=s.length();
        if(s.length()==0){
            return 0;
        }
        for (int i = 0; i < l; i++) {
            int temp = 0;
            for (int j = i; j < l; j++) {
                bool repeat = false;
                // Check if s[j] exists in current substring
                for (int k = i; k < j; k++) {
                    if (s[k] == s[j]) {
                        repeat = true;
                        break;
                    }
                }
                if (repeat)
                    break; // stop expanding if duplicate found
                temp++;
            }
            if (temp > count)
                count = temp;
        }
        return count;
    }
};