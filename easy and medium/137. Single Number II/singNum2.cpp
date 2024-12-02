class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m; 
        for(auto it : nums){
            m[it]++;
        }
        for(auto [num , fre] : m){
            if(fre == 1){
                return num;
            }
        } 
        return -1;
    }
};