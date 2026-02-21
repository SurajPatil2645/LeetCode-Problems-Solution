class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int sum=0;
        int primes[]={2,3,5,7,11,13,17,19,23,29,31};
        for(int i=left;i<=right;i++){
            string r;
            int temp=i;
            while (temp > 0) {
                r += (temp % 2 == 0 ? "0" : "1");
                temp /= 2;
            }
            reverse(r.begin(), r.end());
            int count=0;
            for(int j=0;j<r.length();j++){
                if(r[j]=='1'){
                    count++;
                }
            }
            for(int k=0;k<11;k++){
                if(count==primes[k]){
                    sum++;
                }
            }
        }
        return sum;
    }
};