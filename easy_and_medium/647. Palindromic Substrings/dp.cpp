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
    int countSubstrings(string& s) {
        int count = 0;
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        // check length 1; 
        for(int i = 0; i < s.size(); i++){
            dp[i][i] = true;
            // check length 2;
            count++;
        }
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == s[i + 1]){
                dp[i][i + 1] = true;
                count++;
            }
        }
        // check length 3; 
        for(int length = 3; length <= s.size(); length++){
            for(int i = 0; i <= s.size() - length; i++){
                // 0 + 3 - 1;
                int j = i + length - 1;
                if(dp[i + 1][j - 1] && s[i] == s[j]){
                    dp[i][j] = true;
                    count++;
                }
            }
        }
        // cout << count << endl;
        return count;
    }
};

auto speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

// int main(){
//     string temp = "acbca";
//     vector<string> v;
//     Solution s;
//     s.countSubstrings(temp);
//     return 0;    
// }