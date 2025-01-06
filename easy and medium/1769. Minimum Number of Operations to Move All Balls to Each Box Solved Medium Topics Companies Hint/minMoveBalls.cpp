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
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size(),0);
        if(boxes.size() ==  1){
            return ans;
        }
        // left pfS 
        vector<int>prefixSumLeft(boxes.size(),0);
        vector<int>prefixSumRight(boxes.size(),0);
        
        // count balls
        int balls = 0;

        // preDefineLeft
        boxes[0] == '1' ? balls = 1 : balls = 0; 
        for(int i = 1; i < boxes.size(); i++){
            prefixSumLeft[i] = balls + prefixSumLeft[i - 1];
            if(boxes[i] == '1') balls++;
        }
        // preDefineRight
        balls = 0;
        boxes[boxes.size() - 1] == '1' ? balls = 1 : balls = 0; 
         for(int i = boxes.size() - 2; i >= 0; i--){
            prefixSumRight[i] = balls + prefixSumRight[i + 1];
            if(boxes[i] == '1') balls++;
        }
        for(int i = 0; i < ans.size(); i++){
            ans[i] = prefixSumLeft[i] + prefixSumRight[i];
        } 
        return ans;
    }
};

// brute
// class Solution {
// public:
//     vector<int> minOperations(string boxes) {
//         vector<int> ans;
//         for(int i = 0; i < boxes.size(); i++){
//             int count = 0;
//             for(int j = 0; j < boxes.size(); j++){
//                 if(boxes[j] == '1' && j != i){
//                     count += abs(i - j);
//                 }
//             }
//             ans.push_back(count);
//         }
//         for(auto& it : ans) cout << it << " ";
//         return ans;
//     }
// };
auto speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

// int main() {
//     Solution s;
//     string temp = "001011";
//     s.minOperations(temp);
//     return 0;    
// }
