class Solution {
public:
    bool containsDuplicate(vector<int>& nums) { 
        unordered_map<int,int> m;  
        for(auto it : nums){   
            m[it]++; 
            if(m[it] > 1){ 
            return true;
            }
        }
        return false;
    }
};