class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;  
        int min = INT_MAX; 
        int max = 0; 
        for(auto price : prices){  
            if(price < min){ 
                min = price; 
            }
            int profit = price - min;  
            if(profit > max){ 
                max = profit;
            }
        }
        return max;
    }
};
