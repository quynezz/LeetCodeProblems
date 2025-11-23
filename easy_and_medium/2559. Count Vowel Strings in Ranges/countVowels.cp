#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
const int maxN = 1000001;
#define vii vector<pair<int, int>>
vector<pair<int, int>> adj[maxN];
const int MOD = 1e9;

class Solution {

private:
    bool startAndEnd(string& s) {
        // vowel;
        string temp = "aeiou";
        if (temp.find(s[0]) != string::npos &&
            temp.find(s[s.size() - 1]) != string::npos)
            return true;
        return false;
    }

public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> prefixSum(words.size(), 0);
        startAndEnd(words[0]) ? prefixSum[0] += 1 : prefixSum[0] += 0;
        for (int i = 1; i < words.size(); i++) {
            startAndEnd(words[i]) == true ? prefixSum[i] = prefixSum[i - 1] + 1: prefixSum[i] = prefixSum[i - 1];
        }
        vector<int> vowels(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            int temp = 0;
            if (queries[i][0] == 0) {
                temp = prefixSum[queries[i][1]];
            } else {
                temp = prefixSum[queries[i][1]] - prefixSum[queries[i][0] - 1];
            }
            vowels[i] = temp;
        }
        for(auto it : vowels) cout << it << " ";
        return vowels;
    }
};
auto speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

// int main(){
//     vector<string> words = {"aba","bcb","ece","aa","e"};
//     vector<vector<int>> queries = {{0, 2}, {1, 4}, {1, 1}};
//     Solution s; 
//     s.vowelStrings(words, queries);
//     return 0;
// }