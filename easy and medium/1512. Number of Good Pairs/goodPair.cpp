class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        unordered_map<int,int> m;
        for(auto it : nums) m[it]++;
        for(auto& [num, fre] : m){
            count += (fre * (fre - 1)) / 2;
        }
        return count;
    }
};