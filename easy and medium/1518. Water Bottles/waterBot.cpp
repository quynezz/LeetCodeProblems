class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int temp = numBottles; 
        while(temp / numExchange != 0) {
            int cur = temp % numExchange;
            ans += (temp / numExchange);
            temp /= numExchange; 
            temp += cur;
        }
        return ans;
    }
};