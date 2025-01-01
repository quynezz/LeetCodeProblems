class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> m;
        int maxFre = INT_MIN;
        int ans = 0;
        for(auto it : nums) m[it]++;
        for(auto& [num , fre ] : m){
            maxFre = max(fre,maxFre);
        }
        for(auto&[num , fre] : m){
            if(fre == maxFre){
                ans += fre;
            }
        }
        return ans;
    }
};