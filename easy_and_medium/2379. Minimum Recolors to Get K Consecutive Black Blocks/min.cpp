class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int count = INT_MAX; 
            int n = blocks.size();
            if(k > blocks.size()) return 0; 
            vector<int> dp(blocks.size(),0);
            blocks[0] == 'W'? dp[0] = 1 : dp[0] = 0; 
            if(blocks[0] == 'B' && k == 1) return dp[0];
            if(blocks.size() == 1)count = dp[0];
            cout << dp[0] << " ";
            for(int i = 1; i < blocks.size(); i++){
                blocks[i] == 'W' ? dp[i] = dp[i - 1] + 1 : dp[i] = dp[i - 1];
                if(i == k - 1){
                    count = min(count, dp[i]);
                }else if(i > k - 1){
                    int index = i - k;
                    count = min(dp[i] - dp[index],count);
                }
            }
         
            return count;
        }
    };