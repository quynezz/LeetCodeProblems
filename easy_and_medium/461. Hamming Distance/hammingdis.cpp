class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        while( x != 0 || y != 0 ){ 
            int i = x % 2; 
            int j = y % 2; 
            if(i != j){ 
                count++; 
            }
            x >>= 1;
            y >>= 1;
        }
        return count;
    }
    // 1 (0  0    0    1)
    // same dif same dif => 2 dif => ans = 2;
    // 4 (0  1    0    0)

};