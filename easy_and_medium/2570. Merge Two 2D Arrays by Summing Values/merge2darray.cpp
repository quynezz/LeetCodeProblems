class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            unordered_map<int,int> m;
            vector<vector<int>> v;
            for(auto it : nums1){
                int idx = it[0];
                int val = it[1];
                m[idx] = val;
            }
            for(auto it : nums2){
                int idx = it[0];
                int val = it[1];
                if(m.count(idx)){
                    m[idx] += val;
                }else{
                    m[idx] = val;
                }
            }
            for(auto& [idx , val] : m){
                v.push_back({idx,val});
            }
    
            sort(v.begin(),v.end(),[&](vector<int> a,vector<int>b){
                return a[0] < b[0];
            });
            return v;
        }
    };