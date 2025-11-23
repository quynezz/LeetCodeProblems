class Solution {
public:
    int accountBalanceAfterPurchase(int n) {
        int ans = 100;
        if(n < 10){
            if(n >= 5){
                return ans - 10;
            }else if (n < 5){
                return ans; 
            }
        }else if(n == 100){
            return ans - n;
        }else if(n >= 10){
            if(n == 10){
                return ans - 10;
            }else{
                int k = n;
                int temp = k % 10;
                if(temp >= 5){
                    return ans - (ceil(n / 10.0) * 10);
                }else{
                    return ans - (floor(n / 10.0) * 10);
                }
            }
        }
        return -1;
    }
};