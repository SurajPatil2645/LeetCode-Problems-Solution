class Solution {
public:
    int reverseBits(int n) {
        int x = 0;
        for (int i = 0; i < 32; i++) {
            int bit = n % 2;
            // To reverse, the first bit found (LSB) becomes the 31st bit (MSB)
            x = (x << 1) | bit; 
            n /= 2;
        }
        return x;
    }
};