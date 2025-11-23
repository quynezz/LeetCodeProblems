class Solution {
public:
    int findComplement(int num) { 
        if(num == 0){ 
            return 1;
        }
        int bit = ~0;
        while(num & bit){ 
            bit <<= 1;
        } 
        return num ^ ~bit;
    }
};