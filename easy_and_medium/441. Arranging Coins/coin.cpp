class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        int ans = 0; 
        int temp = 0;
        while(true){ 
            if(n >= i){ 
            temp = n - i; 
                ans = i;
                i++;
                n = temp;
                } else {
                break; 
            }
        }
        return ans;
    }
};