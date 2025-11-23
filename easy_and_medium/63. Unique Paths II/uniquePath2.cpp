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
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        if(v[0][0] == 1 || v[m - 1][n - 1] == 1){
            cout << 0 << endl;
         return 0;
        }
        vector<vector<ll>> dp(m,vector<ll>(n,0));
        dp[0][0] = 1; 
        for(int i = 1; i < m; i++){
            if(v[i][0] == 0){
                dp[i][0] = dp[i - 1][0];
            }
        }
        for(int j = 1; j < n; j++){
            if(v[0][j] == 0){
                dp[0][j] = dp[0][j - 1];
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(v[i][j] == 0){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        cout << dp[m - 1][n - 1];
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
//     vector<vector<int>> v = {{0,1,0},{0,0,0},{0,0,0}};
//     Solution s;
//     s.uniquePathsWithObstacles(v);
//     return 0;    
// }