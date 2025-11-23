class Solution {
public:
    int maxProfit(vector<int>& prices) { 
        int stock = 0;
        for(int i = 0; i < prices.size() - 1; i++){ 
            if(prices[i] > prices[i + 1]){ 
                continue;
            }
            stock += prices[i + 1] - prices[i];;
        }
        return stock;
    }
};