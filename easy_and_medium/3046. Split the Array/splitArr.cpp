class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto it : nums){
            m[it]++;
        }
        for(auto& [num,fre] : m){
            if(fre > 2){
                return false;
            }
        }
        return true;
    }
};