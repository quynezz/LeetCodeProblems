class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) { 
        vector<int> v;
        unordered_map<int,int> m;
        for(auto it : nums){ 
            m[it]++;
        }
        for(int i = 1; i <= nums.size(); i++){ 
            if(!m.count(i)){ 
                v.push_back(i);
            }
        }
        return v;
    }
};