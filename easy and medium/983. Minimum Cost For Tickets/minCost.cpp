class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> s(days.begin(),days.end());
        int dayMax = days.back();
        vector<int> dp(dayMax + 1, 0);
        for(int i = 1; i <= dayMax; i++){
            if(!s.count(i)){
                dp[i] = dp[i - 1];
            }else{
             dp[i] = min({dp[i - 1] + costs[0],dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]});
            }
        }
        return dp[dayMax];
    }
};