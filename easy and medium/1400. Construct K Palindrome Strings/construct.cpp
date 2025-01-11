#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
const int maxN = 1000001;
#define vii vector<pair<int, int>>
vector<pair<int, int>> adj[maxN];
const int MOD = 1e9;

// Input: s = "annabelle", k = 2
// first: anna, elble
// 1, 2, 2, 2, 2 
// 
class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.size()) return false;
        unordered_map<char,int> m;
        int countOdd = 0;
        bool flag = false;
        for(int i = 0; i < s.size(); i++) m[s[i]]++;
        for(auto& it : m){
            if(it.second % 2 != 0){
                countOdd++;
            }
        }
         countOdd > k ? flag = false : flag = true;
         cout << static_cast<bool>(flag) << endl;
         return flag;
    }
};

auto speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

// int main() {
//     string temp = "leetcode";
//     int k = 3;
//     Solution s; 
//     s.canConstruct(temp,k);
// }
 