class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto it : nums){
            m[it]++;
        }
        int count = 0;
        for(auto& [num, fre] : m){
            if(m.find(num - 1) != m.end()){
                int temp = fre + m[num-1];
                count = max(count,temp);
            }
        }
        return count;
    }
};