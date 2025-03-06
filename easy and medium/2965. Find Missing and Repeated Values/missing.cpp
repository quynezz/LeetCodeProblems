class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            unordered_map<int,int> m;
            int count = 0; 
            for(int i = 0; i < grid.size(); i++){
                for(int j = 0; j < grid[i].size(); j++){
                    m[grid[i][j]]++;
                    count++;
                }
            }
            vector<int> ans;
            for(auto [num,fre] : m){
                if(fre > 1) ans.push_back(num);
            }
            for(int i = 1; i <= count; i++){
                if(m.find(i) == m.end()){
                    ans.push_back(i);
                }
            }
            return ans;
        }
    };