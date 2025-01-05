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
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        auto charToInt = [](char c) { return c - 'a'; };
        auto intToChar = [](int x) { return 'a' + x; };
        vector<int> arrChar(n, 0);
        for (int i = 0; i < n; i++) {
            arrChar[i] = charToInt(s[i]);
        }

        vector<int> prefixSum(n + 1, 0); // Prefix sum array
        for (int i = 0; i < shifts.size(); i++) {
            int l = shifts[i][0];
            int r = shifts[i][1];
            int direction = shifts[i][2];
            if (direction == 1) {
                prefixSum[l] += 1;
                prefixSum[r + 1] -= 1;
            } else { 
                prefixSum[l] -= 1;
                prefixSum[r + 1] += 1;
            }
        }
        for (int i = 1; i < n; i++) {
            prefixSum[i] += prefixSum[i - 1];
        }

        // Apply shifts and construct the resulting string
        for (int i = 0; i < n; i++) {
            int newChar = (arrChar[i] + prefixSum[i]) % 26;
            if (newChar < 0) newChar += 26; // Handle negative shifts
            s[i] = intToChar(newChar);
        }

        cout << s << endl; // Output the result
        return s;
    }
};

auto speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

// int main() {
//     Solution s;
//     // Example input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
//     string temp = "abc";
//     vector<vector<int>> v = {{0, 1, 0}, {1, 2, 1}, {0, 2, 1}};
//     s.shiftingLetters(temp, v);
//     return 0;    
// }
