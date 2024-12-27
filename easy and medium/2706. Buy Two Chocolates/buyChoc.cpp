class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int choc = 0;
        int temp = money;
        sort(prices.begin(),prices.end(), [&](int a, int b){
            return a < b;
        });
        int i = 0;
        while(money >= 0 && choc != 2){
            int n = prices[i];
            i++;
            money -= n;
            choc++;
        }
        if(choc == 2 && money >= 0){
            return money;
        }
        return temp;
    }
};