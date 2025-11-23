class Solution {
    private:
    void lcs(string& s1, string& s2, int m, int n, string& res) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
    
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                res.push_back(s1[i - 1]);
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                res.push_back(s1[i - 1]);
                i--;
            } else {
                res.push_back(s2[j - 1]);
                j--;
            }
        }
    
        while (i > 0) {
            res.push_back(s1[i - 1]);
            i--;
        }
        
        // Add remaining characters from str2 (if any)
        while (j > 0) {
            res.push_back(s2[j - 1]);
            j--;
        }
        
        reverse(res.begin(), res.end());
    
    
    }
    
    public:
        string shortestCommonSupersequence(string str1, string str2) {
            string res = "";
            int m = str1.size();
            int n = str2.size();
            lcs(str1,str2,m,n,res);
            return res;
    
        }
    };