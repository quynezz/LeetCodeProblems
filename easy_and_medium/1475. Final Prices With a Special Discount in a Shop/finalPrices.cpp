class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        vector<int> v(prices.size(),0);
        for(int i = prices.size() - 1; i >= 0 ; i--){
            while(!st.empty() && st.top() > prices[i]){
                st.pop();
            }
            st.empty() ? v[i] = prices[i] : v[i] = prices[i] - st.top();
            st.push(prices[i]);
        }
        return v;
    }
};



// brute force 


class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> v;
        for(int i = 0; i < prices.size() - 1; i++){
            int temp = 0;
            bool discount = false;
            for(int j = i + 1; j < prices.size(); j++){
                if(j > i && prices[j] <= prices[i]){
                    temp = prices[i] - prices[j];
                    discount = true;
                    break;
                }
            }
                if(discount == true){
                    v.push_back(temp);
                }else{
                    v.push_back(prices[i]);
                }
        }
        v.push_back(prices[prices.size() - 1]);
        return v;
    }
};