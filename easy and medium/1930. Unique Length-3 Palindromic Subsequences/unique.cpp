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
    int countPalindromicSubsequence(string s) {
        // "abcaa"
        int ans = 0;
        for(int i = 'a'; i <= 'z'; i++){
            int left = s.find(i); 
            int right = s.rfind(i);
            if(left < right){
                unordered_set<char> st;
                for(int j = left + 1; j < right; j++){
                    st.insert(s[j]);
                }
                ans += st.size();
            }
        }
        cout << ans << endl;
        return ans;
    }
};
auto speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

// int main(){
//     string temp = "aabca";
//     vector<int> v = {};
//     Solution s;
//     s.countPalindromicSubsequence(temp);
//     return 0;    
// }