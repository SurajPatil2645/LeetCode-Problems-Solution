class Solution {
public:
    bool checkString(string s) {
        int cura=0,curb=0;
        bool bocc=false;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'){
                cura=i;
            }
            else if(s[i]=='b'){
                curb=i;
                bocc=true;
            }
            if(cura>curb && (bocc)) return false;
        }
        return true;
    }
};