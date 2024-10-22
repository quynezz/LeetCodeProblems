class Solution {
public:
//  take 4 bits as an example: 
// 1011 to 1101 
// take each last significant bits of 1011 and place it to ans; 
// shift left ans to store another bits and shift right the "n" to delete the number that just store in ans
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        for(int i = 0; i < 32; i++){  
            ans <<= 1; 
            ans |= ( n & 1);  
            n >>= 1;
        }
        return ans;
    }
};