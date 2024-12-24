class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
        int temp = n;
        int k = 1;
            while(temp != 0){
                k *= (temp % 10);
                temp /= 10;
            }
            if(k % t == 0) break;
            n = n + 1;
        }
        return n;
    }
};