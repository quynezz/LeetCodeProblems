#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
const int maxN = 1000001;
#define vii vector<pair<int, int>>
vector<pair<int, int>> adj[maxN];
const int MOD = 1e9;



class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
         int m = grid.size();    // Number of rows
        int n = grid[0].size(); // Number of columns
        int ans = 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; i++){
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }
        for(int j = 1; j < n; j++){
            dp[0][j] = grid[0][j] + dp[0][j - 1];
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = grid[i][j] + min(dp[i - 1][j],dp[i][j - 1]);
            }
        }
        cout << dp[m - 1][n - 1] << endl;
        return dp[m - 1][n - 1];
    }
};
auto speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

// int main() {
//     // vector<int> temp = {4,2,0,3,2,5};
//          //// double vec ///
//     vector<vector<int>> temp = {{1,2,3},{4,5,6}};
//         /// string ///
//     // string s = "";

//     Solution s;
//     s.minPathSum(temp);
//     return 0;    
// }
