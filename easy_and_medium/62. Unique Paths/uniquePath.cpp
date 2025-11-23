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
    int uniquePaths(int m, int n) {
        // Create a DP table with dimensions m x n
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Initialize the first row and the first column
        for (int i = 0; i < m; i++) dp[i][0] = 1;  // Only one way to move down
        for (int j = 0; j < n; j++) dp[0][j] = 1;  // Only one way to move right

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];  // Paths from above + left
            }
        }
        return dp[m - 1][n - 1];
    }
};
auto speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

// int main(){
//     Solution s;
//     s.uniquePaths(3,7);
//     return 0;    
// }