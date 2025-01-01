class Solution {
public:
    int countOdds(int low, int high) {
        int n = (high - low + 1);
        int ans = 0;
        if(n % 2 == 0){
            ans = n / 2;
        }else{
            if(low % 2 != 0 || high % 2 != 0) ans = (n / 2) + 1;
            else ans = n / 2;
        }
        return ans;
    }
};