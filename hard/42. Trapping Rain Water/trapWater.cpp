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
    int trap(vector<int>& height) {
        if(height.size() <= 2){
            return 0;
        }
        int capture = 0;
        vector<int> dpL(height.size(),0);
        vector<int> dpR(height.size(),0);
        vector<int> ret(height.size(),0);
        dpL[0] = height[0];
        dpR[height.size() - 1] = height[height.size() - 1];
        for(int i = 1; i < height.size(); i++){
            if(height[i] > dpL[i - 1]){
                dpL[i] = height[i];
            }else{
                dpL[i] = dpL[i - 1];
            }
        }
        for(int i = height.size() - 2; i >= 0; i--){
            if(height[i] > dpR[i + 1]){
                dpR[i] = height[i];
            }else{
                dpR[i] = dpR[i + 1];
            }
        }
        for(int i = 0; i < height.size(); i++){
            ret[i] = min(dpL[i],dpR[i]);
        }        
        for(int i = 0; i < height.size(); i++){
            int temp = ret[i] - height[i];
            if(temp < 0){
                continue;
            }else{
                capture += temp;
            }
        }
        cout << capture << endl;
        return capture;
    }
};


auto speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

// int main() {
//     vector<int> temp = {4,2,0,3,2,5};
//     Solution s;
//     s.trap(temp);
//     return 0;    

// }
