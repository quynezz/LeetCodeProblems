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
    int minimumAverageDifference(vector<int>& nums) {
        ll ans = LLONG_MAX;
        int index = 0;
        if(nums.size() == 0){
            // cout << index << endl;
            return index;
        } 
        vector<ll> prefixSum(nums.size(),0); 
        // define pS;
        prefixSum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
        prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        
        for(int i = 0; i < prefixSum.size(); i++){
            ll ret = prefixSum[i] / (i + 1);
            ll ter = (i == prefixSum.size() - 1) ? 0 : (prefixSum[nums.size() - 1] - prefixSum[i]) / (nums.size() - i - 1); 
            ll dif = abs(ret - ter);
            if(dif < ans) {
                index = i;
                ans = dif;
            }
        }
        // cout << index << endl;
        return index;
    }
};
auto speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

// int main(){
//     vector<int> test = {0};
//     Solution s;
//     s.minimumAverageDifference(test);
//     return 0;    
// }