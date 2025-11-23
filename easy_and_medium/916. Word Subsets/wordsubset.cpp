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
// Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
// Output: ["facebook","google","leetcode"]
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int> m1; 
        vector<string> ans;
        for(auto it : words2) {
            unordered_map<char,int> temp;
            for(auto ti : it){
                temp[ti]++;
            }
            for(int i = 0; i < 26; i++){
                m1[i + 'a'] = max(m1[i + 'a'],temp[i + 'a']);
            }
        }
        for(int i = 0; i < words1.size(); i++){
            unordered_map<char,int> temp;
            bool ok = true;
            for(int j = 0; j < words1[i].size(); j++){
                temp[words1[i][j]]++; 
            }
            for(int k = 0; k < 26; k++){
                if(temp[k + 'a'] < m1[k + 'a']){
                    ok = false;
                    break;
                }
            }
            if(ok){
                ans.push_back(words1[i]);
            }
        }
        for(auto it : ans){
            cout << it << " ";
        }
        return ans;
    }
};

auto speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

// int main() {
//     vector<string> v = {"amazon","apple","facebook","google","leetcode"};
//     vector<string> v2 = {"l","e"};
//     Solution s; 
//     s.wordSubsets(v,v2);
// }