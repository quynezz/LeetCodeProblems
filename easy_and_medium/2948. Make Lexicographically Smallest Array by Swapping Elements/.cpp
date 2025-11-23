#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1000001;
const int MOD = 1e9;
#define vii vector<pair<int, int>>



class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<queue<int>> v;
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        // for(auto it : temp) cout << it << " ";
        cout << endl;
        unordered_map<int,int> m;
        int index = 0;
        for(int i = 0; i < temp.size(); i++){
            if(v.empty()){
                v.push_back(queue<int>());
                v[index].push(temp[i]);
                m[temp[i]] = index;
            }else if(abs(temp[i] - temp[i - 1]) > limit){
                index++;
                v.push_back(queue<int>());
                v[index].push(temp[i]);
                m[temp[i]] = index; 
            }else if(abs(temp[i] - temp[i - 1] <= limit)){
                v[index].push(temp[i]);
                m[temp[i]] = index;
            }
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(!v[m[nums[i]]].empty()){
                nums[i] = v[m[nums[i]]].front();
                v[m[nums[i]]].pop();
            }
        }
        // for(auto it : res){
        //     cout << it << " ";
        // }
        return nums;
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
//     vector<int> v = {1,5,3,9,8}; 
//     int limit = 3;
//     s.lexicographicallySmallestArray(v,limit);
// }
