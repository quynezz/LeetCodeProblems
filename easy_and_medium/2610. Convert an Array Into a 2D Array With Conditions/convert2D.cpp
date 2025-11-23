class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto it : nums) {
            m[it]++;
        }
        vector<vector<int>> v;
        while (!m.empty()) {
            vector<int> temp;
            vector<int> e;
            for (auto& [num, fre] : m) {
                temp.push_back(num);
                fre--;
                if(fre == 0){
                    e.push_back(num);
                }
            }
            v.push_back(temp);
            for(auto it : e){
                m.erase(it);
            }
        }
        return v;
    }
};