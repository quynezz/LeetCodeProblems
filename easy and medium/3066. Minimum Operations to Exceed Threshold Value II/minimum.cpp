#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
const int maxN = 1000001;
const int MOD = 1e9;
#define vii vector<pair<int, int>>

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int count = 0;
            priority_queue<long long,vector<long long>,greater<>> pq(nums.begin(),nums.end());
            while(pq.top() < k){
                long long n = pq.top(); 
                pq.pop(); 
                long long m = pq.top();
                pq.pop();
                pq.push(min(n,m) * 2 + max(n,m));
                count++;
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
// int main() {   
//     Solution s; 
//     vector<int> nums = {1,1,2,4,9};
//     int k = 20;
//     s.minOperations(nums,k);
// }
