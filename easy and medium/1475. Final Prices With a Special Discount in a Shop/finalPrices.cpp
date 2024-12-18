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