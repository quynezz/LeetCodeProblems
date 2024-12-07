class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> v;
        unordered_map<int,int> m;
        for(auto it : nums){
            for(auto ti : it){
                m[ti]++;
            }
        }
        for(auto [num , fre] : m){
            if(fre == nums.size()){
                v.push_back(num);
            }
        }
        sort(v.begin(),v.end());
        return v; 
    }
};